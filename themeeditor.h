#ifndef THEMEEDITOR_H
#define THEMEEDITOR_H

#include "qheaders.h"
#include "themedata.h"
#include "filehandler.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class ThemeEditor;
}
QT_END_NAMESPACE

class ThemeEditor : public QMainWindow
{
    Q_OBJECT

public:
    ThemeEditor(QWidget *parent = nullptr);
    ~ThemeEditor();

private:
    Ui::ThemeEditor *ui;
    FileHandler fileHandler;
    ThemeData themeData;

    QStandardItemModel* themeItemModel;
};
#endif // THEMEEDITOR_H
