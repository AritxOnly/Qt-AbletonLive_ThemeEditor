#ifndef THEMEEDITOR_H
#define THEMEEDITOR_H

#include <QMainWindow>

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
};
#endif // THEMEEDITOR_H
