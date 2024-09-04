#pragma once

// 编辑UI类

#ifndef EDITORUI_H
#define EDITORUI_H

#include "qheaders.h"
#include "themedata.h"

class ThemeEditor;

class EditorUI : public QWidget
{
    Q_OBJECT
public:
    explicit EditorUI(QWidget *parent = nullptr);

    void TextChanged(const QString &text);
    void ThemeDataChanged(ThemeData* td);
    void ItemDoubleClicked(const QModelIndex &modelIndex);

    void setThemeEditor(ThemeEditor *_editor);

private:
    ThemeData* themeData = nullptr;

    QVBoxLayout *vLayout;
    QLineEdit *searchBar;
    QListView *dataList;
    QStandardItemModel *itemModel;
    QPixmap transPix;

    ThemeEditor* editor = nullptr;

    void SetItemColor(QStandardItem* item, uint c);
};

#endif // EDITORUI_H
