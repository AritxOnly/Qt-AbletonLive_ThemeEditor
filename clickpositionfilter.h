#ifndef CLICKPOSITIONFILTER_H
#define CLICKPOSITIONFILTER_H

#include "qheaders.h"


class ClickPositionFilter : public QObject
{
public:
    explicit ClickPositionFilter(QToolButton *button);

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;


private:
    QToolButton *button;
};


#endif // CLICKPOSITIONFILTER_H
