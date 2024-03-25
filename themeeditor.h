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

    void initListWidget(QStringList);

public slots:
    void onDoubleClickedItem();
    void onButtonHelpClicked();

private:
    Ui::ThemeEditor *ui;
    FileHandler file;
    ThemeData td;
    QString fileDir;

    bool isFileLoad;
};
#endif // THEMEEDITOR_H
