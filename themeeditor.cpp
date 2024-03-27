#include "themeeditor.h"
#include "ui_themeeditor.h"
#include "clickpositionfilter.h"
#include "editorui.h"


ThemeEditor::ThemeEditor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ThemeEditor)
{

    ui->setupUi(this);


    themeItemModel = new QStandardItemModel(ui->themeList);
    ui->themeList->setModel(themeItemModel);

    themeItemModel->clear();
    for(auto str:fileHandler.fileList)
        themeItemModel->appendRow(new QStandardItem(str.remove(".ask")));


    connect(ui->themeList,
            &QListView::doubleClicked,
            this,
            &ThemeEditor::ThemeListDoubleClicked);

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


    //
    //关于和帮助
    connect(ui->helpButton, &QPushButton::clicked, this, &ThemeEditor::HelpButtonClicked);

    themeData.BindOnModified(this,&ThemeEditor::ThemeModified);

    //取色器用法QColor Dialog，将QColor的RGB转化为HEX(Debug测试信号链接)
//    connect(ui->actionDebug_Output, &QAction::triggered, this, [=]() {
//        QColor color = QColorDialog::getColor(Qt::white,
//                                              this,
//                                              "Select the desired color...");
//        QRgb mRGB = qRgb(color.red(), color.green(), color.blue());
//        QString colorHex = QString::number(mRGB, 16);
//        qDebug() << colorHex;
//    });

}

ThemeEditor::~ThemeEditor()
{
    delete ui;
}

void ThemeEditor::ThemeListDoubleClicked(const QModelIndex &index)
{
    ui->askColorList->clear();
    //bug exists themeData isn't clear
    currentTheme = themeItemModel->data(index).toString();
    themeData.LoadData((fileHandler.folderPath+currentTheme+".ask").toUtf8());
    ui->currentTheme->setText(currentTheme);
    EditorUI *editor = new EditorUI(this, &themeData);
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
        fileHandler.ListThemeFolder();
        themeItemModel->clear();
        for(auto str:fileHandler.fileList)
            themeItemModel->appendRow(new QStandardItem(str.remove(".ask")));
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
        themeData.SaveData(fileHandler.folderPath+currentTheme+".ask");
    }
    else
    {
        auto path = QFileDialog::getSaveFileName(this,
                                                 "Save Theme File As...",
                                                 currentTheme+".ask",
                                                 "*.ask");
        themeData.SaveData(path);
    }
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
    msgBoxHelp.setText("Ableton Live Theme Editor\nContact Us on Github!");
    msgBoxHelp.setStyleSheet("background-color:#2a2a2a; color: #a0a0a2;");
    //按钮
    QPushButton *btnAbout;
    QPushButton *btnHelp;

    btnAbout = msgBoxHelp.addButton("About", QMessageBox::ActionRole);
    btnHelp = msgBoxHelp.addButton("Help", QMessageBox::ActionRole);
    msgBoxHelp.addButton("Close", QMessageBox::RejectRole)->setVisible(false);
    //槽连接
    connect(btnAbout, &QPushButton::clicked, this, [=]() {
        QString url = "https://github.com/AritxOnly/Qt-AbletonLive_ThemeEditor";
        QDesktopServices::openUrl(url);
    });

    connect(btnHelp, &QPushButton::clicked, this, [=]() {
        QString url = "https://github.com/AritxOnly/Qt-AbletonLive_ThemeEditor/issues";
        QDesktopServices::openUrl(url);
    });

    msgBoxHelp.setWindowModality(Qt::NonModal);
    msgBoxHelp.exec();
}

void ThemeEditor::ThemeModified()
{
    ui->currentTheme->setText(currentTheme+"(modified)");
}

// 重载窗口关闭事件
void ThemeEditor::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton close =
        QMessageBox::question(this,"Quit",
        "Are you sure to exit the editor?\nPlease make sure you have saved all your works.",
        QMessageBox::Cancel | QMessageBox::Yes);
    if(close == QMessageBox::Yes)
        event->accept();
    else
        event->ignore();
}
