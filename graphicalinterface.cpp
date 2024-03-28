#include "graphicalinterface.h"

GraphicalInterface::GraphicalInterface(QWidget *parent)
    : QWidget(parent)
{

    tp.load(":/pics/resources/pics/template.png");
    tp0.load(":/pics/resources/pics/template0.png");
    img = QImage(tp.width(),tp.height(),QImage::Format::Format_ARGB32);
    norm.LoadData(":/asks/resources/asks/template.ask");

}

void GraphicalInterface::paintEvent(QPaintEvent* event)
{
    if(!themeData)return;
    QPainter painter(this);
    QRect wr = rect(),ir = img.rect();
    double sf = std::min(1.0*wr.width()/ir.width(),1.0*wr.height()/ir.height());
    int w = ir.width()*sf,h = ir.height()*sf;
    QRect dr((wr.width()-w)/2,(wr.height()-h)/2,w,h);
    painter.drawImage(dr,img);
}

void GraphicalInterface::setCurrectTheme(ThemeData* td)
{
    themeData = td;
    img = QImage(tp.width(),tp.height(),QImage::Format::Format_ARGB32);
    for(int i=0,w=tp.width();i<w;++i)
    {
        for(int j=0,h=tp.height();j<h;++j)
        {
            uint rgb = tp0.pixel(i,j)&0xffffff;
            if(rgb>0x200000)
            {
                img.setPixel(i,j,rgb|0xff000000);
                continue;
            }
            if(rgb&0x0f0f0f)
            {
                if(i)img.setPixel(i,j,img.pixel(i-1,j));
                else img.setPixel(i,j,img.pixel(i,j-1));
                continue;
            }
            int c = ((rgb&0xf0)>>4)|((rgb&0xf000)>>8)|((rgb&0xf00000)>>12);
            if(c>=td->size())
            {
                img.setPixel(i,j,rgb|0xff000000);
                continue;
            }
            auto tag = td->at(c);

            if(tag.type == ThemeData::rgb)
            {
                img.setPixel(i,j,tag.i|0xff000000);
            }

        }
    }



    for(int i=0,w=tp.width();i<w;++i)
    {
        for(int j=0,h=tp.height();j<h;++j)
        {
            unsigned int rgb = tp.pixel(i,j)&0xffffff;
            if(rgb&0x0f0f0f||rgb>0x200000)
            {
                continue;
            }
            int c = ((rgb&0xf0)>>4)|((rgb&0xf000)>>8)|((rgb&0xf00000)>>12);
            if(c>=td->size())
            {
                continue;
            }
            auto tag = td->at(c);
            if(tag.type == ThemeData::rgba)
            {
                uint al = tag.i&0xff,r=tag.i>>8;
                uint p = img.pixel(i,j)&0xffffff;
                auto f = [](uint x,uint y,uint al)
                {
                    return ((x&0xff)*al+(y&0xff)*(256-al))>>8;
                };
                r = f(r,p,al)|(f(r>>8,p>>8,al)<<8)|(f(r>>16,p>>16,al)<<16);
                img.setPixel(i,j,r|0xff000000);
            }

        }
    }

    this->update();
}
