#include "themeeditor.h"

#include "ui_themeeditor.h"





ThemeEditor::ThemeEditor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ThemeEditor)
{
    ui->setupUi(this);





    themeItemModel = new QStandardItemModel(ui->themeList);
//    themeItemModel->appendRow(new QStandardItem("Hello"));
    ui->themeList->setModel(themeItemModel);

    for(auto& str:fileHandler.fileList)
    {
        themeItemModel->appendRow(new QStandardItem(str));
    }



}

ThemeEditor::~ThemeEditor()
{
    delete ui;
}

