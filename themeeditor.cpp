#include "themeeditor.h"
#include "settingsinterface.h"
#include "ui_themeeditor.h"
#include "clickpositionfilter.h"
#include "editorui.h"
#include "redohandler.h"

#include <iostream>

ThemeEditor::ThemeEditor(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::ThemeEditor), themeData(new ThemeData)
{
    //封包前修改
    version = "v1.0";

    ui->setupUi(this);

    mainEditor = new EditorUI(ui->demoArea);
    ui->demoArea->layout()->addWidget(mainEditor);
    mainEditor->setThemeEditor(this);

    themeItemModel = new QStandardItemModel(ui->themeList);
    ui->themeList->setModel(themeItemModel);
    connect(ui->themeList,
            &QListView::doubleClicked,
            this,
            &ThemeEditor::ThemeListDoubleClicked);

    ReloadFileList();

    gi = new GraphicalInterface(ui->demoArea);
    ui->demoLayout->addWidget(gi);
    ui->demoLayout->setStretch(1,3);

    ui->importExport->setText("Import");
    QMenu* importExportMenu = new QMenu();
    connect(importExportMenu->addAction("Export"),
            &QAction::triggered,
            this,
            &ThemeEditor::ImportExportAltered);
    connect(ui->importExport,
            &QToolButton::clicked,
            this,
            &ThemeEditor::ImportExportClicked);
    importExportMenu->setStyleSheet("padding: 5px; background-color:#2a2a2a; font-size:15px; color:#c0c0c3;");
    importExportMenu->setFixedWidth(100);
    ui->importExport->setMenu(importExportMenu);
    ui->importExport->installEventFilter(new ClickPositionFilter(ui->importExport));


    ui->saveSaveAs->setText("Save");
    QMenu* saveSaveAsMenu = new QMenu();
    connect(saveSaveAsMenu->addAction("SaveAs..."),
            &QAction::triggered,
            this,
            &ThemeEditor::SaveSaveAsAltered);
    connect(ui->saveSaveAs,
            &QToolButton::clicked,
            this,
            &ThemeEditor::SaveSaveAsClicked);
    saveSaveAsMenu->setStyleSheet("padding: 5px; background-color:#2a2a2a; font-size:15px; color:#c0c0c3;");
    saveSaveAsMenu->setFixedWidth(100);
    ui->saveSaveAs->setMenu(saveSaveAsMenu);
    ui->saveSaveAs->installEventFilter(new ClickPositionFilter(ui->saveSaveAs));


    ui->currentTheme->setAlignment(Qt::AlignCenter);
    //
    //关于和帮助
    connect(ui->helpButton, &QPushButton::clicked, this, &ThemeEditor::HelpButtonClicked);

    connect(ui->openFolderButton,&QPushButton::clicked, this, &ThemeEditor::OpenFolderButtonClicked);
    connect(ui->settingsButton,&QPushButton::clicked, this, &ThemeEditor::SettingsButtonClicked);

    // themeData->BindOnModified(this,&ThemeEditor::ThemeModified);
    connect(themeData, &ThemeData::Modified, this, &ThemeEditor::ThemeModified);    // 信号与槽修改

    this->setStyleSheet("background-color:#2a2a2a; font-size:15px; color:#c0c0c3;");

    redoHandler = new RedoHandler;
}

ThemeEditor::~ThemeEditor()
{
    delete ui;
}

void ThemeEditor::ThemeListDoubleClicked(const QModelIndex &index)
{
    currentTheme = themeItemModel->data(index).toString();
    themeData->LoadData((fileHandler.folderPath+currentTheme+".ask").toUtf8());
    ui->currentTheme->setText(currentTheme);
    mainEditor->ThemeDataChanged(themeData);
    gi->setCurrectTheme(themeData);
}

void ThemeEditor::ImportExportClicked()
{
    if(ui->importExport->text()=="Import")
    {
        auto path = QFileDialog::getOpenFileName(this, "Import Theme File", "", "*.ask");
        auto name = path.sliced(path.lastIndexOf('/')+1);
        QFile src(path);
        QFile dst(fileHandler.folderPath+name);
        if (!src.open(QIODevice::ReadOnly))return;
        if (!dst.open(QIODevice::WriteOnly))return;
        dst.write(src.readAll());

    }
    else
    {
        if(currentTheme.isNull())
        {
            QMessageBox msg(this);
            msg.setStyleSheet("background-color:#2a2a2a; color: #a0a0a2;");
            msg.setText("    No theme file is open. \nDouble click to open a theme.");
            msg.exec();
            return;
        }
        auto path = QFileDialog::getSaveFileName(this,
                                                 "Export Theme File",
                                                 currentTheme+".ask","*.ask");
        QFile src(fileHandler.folderPath+currentTheme+".ask");
        QFile dst(path);
        if (!src.open(QIODevice::ReadOnly))return;
        if (!dst.open(QIODevice::WriteOnly))return;
        dst.write(src.readAll());
    }
    ReloadFileList();
}

void ThemeEditor::ImportExportAltered()
{
    if(ui->importExport->text()=="Import")
    {
        ui->importExport->setText("Export");
        ui->importExport->menu()->actions()[0]->setText("Import");
    }
    else
    {
        ui->importExport->setText("Import");
        ui->importExport->menu()->actions()[0]->setText("Export");
    }
}


void ThemeEditor::SaveSaveAsClicked()
{
    if(currentTheme.isNull())
    {
        QMessageBox msg(this);
        msg.setStyleSheet("background-color:#2a2a2a; color: #a0a0a2;");
        msg.setText("    No theme file is open. \nDouble click to open a theme.");
        msg.exec();
        return;
    }
    if(ui->saveSaveAs->text()=="Save")
    {
        themeData->SaveData(fileHandler.folderPath+currentTheme+".ask");
    }
    else
    {
        auto path = QFileDialog::getSaveFileName(this,
                                                 "Save Theme File As...",
                                                 fileHandler.folderPath+currentTheme+".ask",
                                                 "*.ask");
        themeData->SaveData(path);
        ReloadFileList();

        currentTheme = path.sliced(path.lastIndexOf('/')+1).remove(".ask");
        ui->currentTheme->setText(currentTheme);
    }
    modified=false;
    ui->currentTheme->setText(currentTheme);
}

void ThemeEditor::SaveSaveAsAltered()
{
    if(ui->saveSaveAs->text()=="Save")
    {
        ui->saveSaveAs->setText("SaveAs...");
        ui->saveSaveAs->menu()->actions()[0]->setText("Save");
    }
    else
    {
        ui->saveSaveAs->setText("Save");
        ui->saveSaveAs->menu()->actions()[0]->setText("SaveAs...");
    }
}

void ThemeEditor::HelpButtonClicked()
{
    QMessageBox msgBoxHelp(this);
    //设置窗体信息
    msgBoxHelp.setIcon(QMessageBox::Question);
    msgBoxHelp.setWindowTitle("Information");
    msgBoxHelp.setText("Ableton Live Theme Editor " + version + "\nContact Us on Github!");
    msgBoxHelp.setStyleSheet("background-color:#2a2a2a; color: #a0a0a2;");
    //按钮
    QPushButton *btnAbout;
    QPushButton *btnHelp;
    QPushButton *btnBugReport;

    btnAbout = msgBoxHelp.addButton("About", QMessageBox::ActionRole);
    btnHelp = msgBoxHelp.addButton("Help", QMessageBox::ActionRole);
    btnBugReport = msgBoxHelp.addButton("Bug Report", QMessageBox::ActionRole);
    msgBoxHelp.addButton("Close", QMessageBox::RejectRole)->setVisible(false);
    //槽连接
    connect(btnAbout, &QPushButton::clicked, this, [=]() {
        QString url = "https://github.com/AritxOnly/Qt-AbletonLive_ThemeEditor";
        QDesktopServices::openUrl(url);
    });

    connect(btnHelp, &QPushButton::clicked, this, [=]() {
        //后续维护知识库
        QString url = "https://github.com/AritxOnly/Qt-AbletonLive_ThemeEditor/wiki";
        QDesktopServices::openUrl(url);
    });

    connect(btnBugReport, &QPushButton::clicked, this, [=]() {
        QString url = "https://github.com/AritxOnly/Qt-AbletonLive_ThemeEditor/issues";
        QDesktopServices::openUrl(url);
    });

    msgBoxHelp.setWindowModality(Qt::NonModal);
    msgBoxHelp.exec();
}

void ThemeEditor::OpenFolderButtonClicked()
{
    QDesktopServices::openUrl(QUrl::fromLocalFile(fileHandler.folderPath));
}

void ThemeEditor::SettingsButtonClicked()
{
    auto settingsInterface = new SettingsInterface(this);

    settingsInterface->setWindowTitle("Settings");  // 设置窗体标题

    settingsInterface->setAttribute(Qt::WA_DeleteOnClose);
    settingsInterface->show();

}

void ThemeEditor::ThemeModified()
{
    if(!modified)
    {
        modified = true;
        ui->currentTheme->setText(currentTheme+"(modified)");
    }

    gi->setCurrectTheme(themeData);
}

// 重载窗口关闭事件
void ThemeEditor::closeEvent(QCloseEvent *event)
{
    if(!modified ||
        QMessageBox::question(this,"Quit", "Changes have been made.\n Are you sure to quit?",
        QMessageBox::Cancel | QMessageBox::Yes) == QMessageBox::Yes)
        event->accept();
    else
        event->ignore();
}

void ThemeEditor::OpacityChanged(int value)
{
    setWindowOpacity((windowOpacity = value)/100.0);
}

void ThemeEditor::ReloadFileList()
{
    fileHandler.ListThemeFolder();
    themeItemModel->clear();
    for(auto str:fileHandler.fileList)
        themeItemModel->appendRow(new QStandardItem(str.remove(".ask")));
}

RedoHandler* ThemeEditor::getRedoHandler() {
    return redoHandler;
}

void ThemeEditor::keyPressEvent(QKeyEvent *event) {
    if (event->matches(QKeySequence::Undo)) {
        std::cout << "Undo\n";
        auto undo = redoHandler->undo();
        std::cout << "Getting themeData from:" << undo << "\n";
        if (undo == nullptr) {
            goto pass;
        }
        *themeData = *undo;  // Deep Copy
        std::cout << "Now loading data\n";
        mainEditor->ThemeDataChanged(themeData);
        gi->setCurrectTheme(themeData);
    }
    if (event->matches(QKeySequence::Redo)) {
        std::cout << "Redo\n";
        auto redo = redoHandler->redo();
        if (redo == nullptr) {
            goto pass;
        }
        *themeData = *redo;  // Deep Copy
        mainEditor->ThemeDataChanged(themeData);
        gi->setCurrectTheme(themeData);
    }
    pass:
        QMainWindow::keyPressEvent(event);
}
