#ifndef THEMEEDITOR_H
#define THEMEEDITOR_H

#include <QMainWindow>
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
    QString fileDir;    //文件路径
    ThemeData td;
};
#endif // THEMEEDITOR_H
