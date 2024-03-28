#pragma once

// 编辑UI类

#ifndef EDITORUI_H
#define EDITORUI_H

#include "qheaders.h"
#include "themedata.h"

class EditorUI : public QWidget
{
    Q_OBJECT
public:
    explicit EditorUI(QWidget *parent = nullptr);

    void TextChanged(const QString &text);
    void ThemeDataChanged(ThemeData* td);
    void ItemDoubleClicked(const QModelIndex &modelIndex);

private:
    ThemeData* themeData = nullptr;

    QVBoxLayout *vLayout;
    QLineEdit *searchBar;
    QListView *dataList;
    QStandardItemModel *itemModel;
    QPixmap transPix;

    void SetItemColor(QStandardItem* item, uint c);
};

#endif // EDITORUI_H
