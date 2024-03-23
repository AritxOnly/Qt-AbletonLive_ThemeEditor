#include "themeeditor.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ThemeEditor w;

    //窗体设定：标题，图标
    w.setWindowTitle("Ableton Live Theme Editor");
    w.setWindowIcon(QIcon(":/ico/resource/logo.ico"));


    w.show();
    return a.exec();
}
