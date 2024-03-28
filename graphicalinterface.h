#ifndef GRAPHICALINTERFACE_H
#define GRAPHICALINTERFACE_H

#include "qheaders.h"
#include "themedata.h"

class GraphicalInterface : public QWidget
{
    Q_OBJECT
public:
    explicit GraphicalInterface(QWidget *parent = nullptr);
    void setCurrectTheme(ThemeData* cur);

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    ThemeData norm;
    QImage img,tp,tp0;
    ThemeData* curTheme = nullptr;

};

#endif // GRAPHICALINTERFACE_H
