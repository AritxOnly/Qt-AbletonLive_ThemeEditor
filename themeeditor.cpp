#include "themeeditor.h"

#include "ui_themeeditor.h"


#include <QDebug>
#include <QAction>
#include <QColorDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QDesktopServices>

ThemeEditor::ThemeEditor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ThemeEditor)
{
    ui->setupUi(this);

    FileHandler();
    //
    //文件打开
    connect(ui->actionOpen, &QAction::triggered, this, [=]() {
        fileDir = QFileDialog::getOpenFileName(this,
                                               "Open file",
                                               fileDir,
                                               tr(".ask")); //弹出文件选择框，存储文件路径
        td.LoadData(fileDir.toUtf8());

    });

    //文件保存
    connect(ui->actionSave, &QAction::triggered, this, [=]() {

    });

    //文件另存为
    connect(ui->actionSave_as, &QAction::triggered, this, [=]() {
        fileDir = QFileDialog::getSaveFileName(this,
                                               "Save file as...",
                                               fileDir,
                                               tr("*.ask"));
        td.SaveData(fileDir.toUtf8());
    });

    //
    //关于和帮助
    connect(ui->actionAbout, &QAction::triggered, this, [=]() {
        QString url = "https://github.com/AritxOnly/Qt-AbletonLive_ThemeEditor";
        QDesktopServices::openUrl(url);
    });

    connect(ui->actionSupport, &QAction::triggered, this, [=]() {
        QString url = "https://github.com/AritxOnly/Qt-AbletonLive_ThemeEditor/issues";
        QDesktopServices::openUrl(url);
    });

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

