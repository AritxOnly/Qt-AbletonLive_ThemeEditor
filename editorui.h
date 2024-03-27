#pragma once

// 编辑UI类

#ifndef EDITORUI_H
#define EDITORUI_H

#include "qheaders.h"
#include "themedata.h"
#include "themeeditor.h"
#include "ui_themeeditor.h"

class ThemeEditor;

class EditorUI : public QMainWindow
{
    Q_OBJECT
public:
    explicit EditorUI(ThemeEditor *parent = nullptr, ThemeData *themeData = nullptr);

    ThemeEditor *p; //parent指针，由构造函数传参传入

    void InitAskListView(ThemeData themeData);
    void ColorDialog(ThemeData *themeData);

    QColor Int2QColorRGBA(unsigned int i);


signals:
};

#endif // EDITORUI_H
