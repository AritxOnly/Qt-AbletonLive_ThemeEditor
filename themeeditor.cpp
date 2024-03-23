#include "themeeditor.h"
#include "ui_themeeditor.h"

ThemeEditor::ThemeEditor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ThemeEditor)
{
    ui->setupUi(this);
}

ThemeEditor::~ThemeEditor()
{
    delete ui;
}
