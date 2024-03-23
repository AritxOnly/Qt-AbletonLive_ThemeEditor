#ifndef THEMEEDITOR_H
#define THEMEEDITOR_H

#include <QMainWindow>
#include "pugixml.hpp"

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

    bool readAskFile(const char*);

private:
    Ui::ThemeEditor *ui;
    QString fileDir;    //文件路径

    pugi::xml_document parsed_askFile; //当前打开的ask
};
#endif // THEMEEDITOR_H
