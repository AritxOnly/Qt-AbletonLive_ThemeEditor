#ifndef GRAPHICALINTERFACE_H
#define GRAPHICALINTERFACE_H

#include "qheaders.h"

class GraphicalInterface : public QWidget
{
    Q_OBJECT
public:
    explicit GraphicalInterface(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override {
        QPainter painter(this);
        QImage img;
        img.load("E:\\Pictures\\Coffee.png");
        painter.drawImage(0, 0, img);
    }
};

#endif // GRAPHICALINTERFACE_H
