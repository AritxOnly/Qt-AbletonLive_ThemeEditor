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

    void InitAskListView();

    void ThemeListDoubleClicked(const QModelIndex &index);
    void ImportExportClicked();
    void ImportExportAltered();
    void SaveSaveAsClicked();
    void SaveSaveAsAltered();
    void HelpButtonClicked();
    void ThemeModified();

private:
    Ui::ThemeEditor *ui;
    FileHandler fileHandler;
    ThemeData themeData;

    QStandardItemModel* themeItemModel;
    QString currentTheme;
};
#endif // THEMEEDITOR_H
