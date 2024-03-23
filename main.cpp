#include "themeeditor.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ThemeEditor w;

    //窗体设定：标题，图标
    w.setWindowTitle("Ableton Live主题编辑器");


    w.show();
    return a.exec();
}
