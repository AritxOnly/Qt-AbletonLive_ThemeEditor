#include "qheaders.h"
#include "themeeditor.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFontDatabase::addApplicationFont(":/fonts/resources/fonts/AbletonSansSmall-Regular.ttf");
    QFont font("AbletonSansSmall-Regular");
    font.setLetterSpacing(QFont::PercentageSpacing, 105);
    a.setFont(font);


    ThemeEditor w;



    //窗体设定：标题，图标
    w.setWindowTitle("Ableton Live Theme Editor");
    w.setWindowIcon(QIcon(":/icons/resources/icons/logo.ico"));

//    w.setWindowFlags(Qt::FramelessWindowHint);
    w.show();
    return a.exec();
}
