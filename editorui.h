#ifndef EDITORUI_H
#define EDITORUI_H

#include <QMainWindow>
#include <QWidget>

class EditorUI : public QMainWindow
{
    Q_OBJECT
public:
    explicit EditorUI(QWidget *parent = nullptr);

signals:
};

#endif // EDITORUI_H
