#include "themeeditor.h"

#include "ui_themeeditor.h"


void ThemeEditor::ThemeListDoubleClicked(const QModelIndex &index)
{
    themeData.LoadData((fileHandler.folderPath+themeItemModel->data(index).toString()).toUtf8());
}


ThemeEditor::ThemeEditor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ThemeEditor)
{
    ui->setupUi(this);





    themeItemModel = new QStandardItemModel(ui->themeList);
    ui->themeList->setModel(themeItemModel);

    for(auto& str:fileHandler.fileList)
    {
        themeItemModel->appendRow(new QStandardItem(str));
    }

    connect(ui->themeList, &QListView::doubleClicked, this, &ThemeEditor::ThemeListDoubleClicked);

}

ThemeEditor::~ThemeEditor()
{
    delete ui;
}

