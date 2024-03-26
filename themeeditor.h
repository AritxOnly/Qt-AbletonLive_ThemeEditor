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

    void ThemeListDoubleClicked(const QModelIndex &index);
    void ImportExportClicked();
    void ImportExportAltered();
    void SaveSaveAsClicked();
    void SaveSaveAsAltered();
    void HelpButtonClicked();
    void ThemeModified();

    Ui::ThemeEditor *ui;    // ui指针执为public方便editorui类引用修改

private:
    FileHandler fileHandler;
    ThemeData themeData;

    QStandardItemModel* themeItemModel;
    QString currentTheme;
};
#endif // THEMEEDITOR_H
