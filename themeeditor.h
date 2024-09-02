#ifndef THEMEEDITOR_H
#define THEMEEDITOR_H

#include "qheaders.h"
#include "themedata.h"
#include "filehandler.h"
#include "editorui.h"
#include "graphicalinterface.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class ThemeEditor;
}
QT_END_NAMESPACE

class RedoHandler;

class ThemeEditor : public QMainWindow
{
    Q_OBJECT

public:
    ThemeEditor(QWidget *parent = nullptr);
    ~ThemeEditor();

    QString version;

    void ThemeListDoubleClicked(const QModelIndex &index);
    void ImportExportClicked();
    void ImportExportAltered();
    void SaveSaveAsClicked();
    void SaveSaveAsAltered();
    void HelpButtonClicked();
    void OpenFolderButtonClicked();
    void SettingsButtonClicked();
    void ThemeModified();
    void OpacityChanged(int value);

    int windowOpacity = 100;

    void closeEvent(QCloseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

    RedoHandler* getRedoHandler();

    void ReloadFileList();
private:
    Ui::ThemeEditor *ui;

    FileHandler fileHandler;
    ThemeData* themeData;

    QStandardItemModel* themeItemModel;
    QString currentTheme;

    EditorUI* mainEditor;
    GraphicalInterface* gi;

    RedoHandler *redoHandler;

    bool modified = false;

};
#endif // THEMEEDITOR_H
