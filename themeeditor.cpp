//主窗口构造

#include "themeeditor.h"

#include "ui_themeeditor.h"

#include "editorui.h"

#include <QDebug>
#include <QAction>
#include <QColorDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QDesktopServices>
#include <QListWidgetItem>
#include <QListWidget>
#include <QFileInfo>
#include <QStackedWidget>

ThemeEditor::ThemeEditor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ThemeEditor)
{
    ui->setupUi(this);

    // FileHandler();
    // 对象构造在头文件中，FileHandler file;,后续路径使用FileHandler对象操作
    //

    //创建编辑器UI
    EditorUI editorUi(this);

    initListWidget(file.fileList);

    //槽函数，双击列表项目激活
    connect(ui->listWidget,
            &QListWidget::doubleClicked,
            this,
            &ThemeEditor::onDoubleClickedItem);

    //第三方目录
    connect(ui->pushButtonOpenCustom, &QPushButton::clicked, this, [=]() {
        QString fileDir = QFileDialog::getOpenFileName(this,
                                                       "Open file",
                                                       file.folderPath,
                                                       tr("*.ask(Live Theme File)")); //弹出文件选择框，存储文件路径

        td.LoadData(fileDir.toUtf8());
    });

    //
    //关于和帮助
    connect(ui->pushButtonHelp, &QPushButton::clicked, this, &ThemeEditor::onButtonHelpClicked);

    //取色器用法QColor Dialog，将QColor的RGB转化为HEX(Debug测试信号链接)
    connect(ui->actionDebug_Output, &QAction::triggered, this, [=]() {
        QColor color = QColorDialog::getColor(Qt::white,
                                              this,
                                              "Select the desired color...");
        QRgb mRGB = qRgb(color.red(), color.green(), color.blue());
        QString colorHex = QString::number(mRGB, 16);
        qDebug() << colorHex;
    });

}

ThemeEditor::~ThemeEditor()
{
    delete ui;
}

void ThemeEditor::initListWidget(QStringList fileList)
{
    int itemCount = fileList.count();
    for(int cycle = 0; cycle < itemCount; cycle++)
    {
        QListWidgetItem *item = new QListWidgetItem;
        //初始化一个空子项

        item->setSizeHint(QSize(ui->listWidget->width(), 40));
        //设置这个子项的大小

        QFileInfo file(fileList.at(cycle));
        item->setText(file.fileName());
        //item显示文件名，设置显示样式

        ui->listWidget->addItem(item);
    }
}

void ThemeEditor::onDoubleClickedItem()
{
    QString fileDir = file.folderPath;
    fileDir.append(ui->listWidget->currentItem()->text());
    qDebug() << fileDir;
}

void ThemeEditor::onButtonHelpClicked()
{
    QMessageBox msgBoxHelp(this);
    //设置窗体信息
    msgBoxHelp.setIcon(QMessageBox::Question);
    msgBoxHelp.setWindowTitle("Help & About");
    msgBoxHelp.setText("Ableton Live Theme Editor\nContact Us on Github");
    //按钮
    QPushButton *btnAbout;
    QPushButton *btnHelp;

    btnAbout = msgBoxHelp.addButton("About", QMessageBox::ActionRole);
    btnHelp = msgBoxHelp.addButton("Help", QMessageBox::ActionRole);
    msgBoxHelp.addButton("Close", QMessageBox::RejectRole);

    //槽连接
    connect(btnAbout, &QPushButton::clicked, this, [=]() {
        QString url = "https://github.com/AritxOnly/Qt-AbletonLive_ThemeEditor";
        QDesktopServices::openUrl(url);
        delete btnAbout;    delete btnHelp;
    });

    connect(btnHelp, &QPushButton::clicked, this, [=]() {
        QString url = "https://github.com/AritxOnly/Qt-AbletonLive_ThemeEditor/issues";
        QDesktopServices::openUrl(url);
        delete btnAbout;    delete btnHelp;
    });

    msgBoxHelp.exec();
}
