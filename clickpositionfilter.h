#ifndef CLICKPOSITIONFILTER_H
#define CLICKPOSITIONFILTER_H

#include "qheaders.h"


class ClickPositionFilter : public QObject
{
public:
    explicit ClickPositionFilter(QToolButton *button);

protected:
    bool eventFilter(QObject *obj, QEvent *event) override
    {
        if (obj == button)
        {
            if (event->type() == QEvent::MouseButtonPress)
            {
                QMouseEvent *mouseEvent = reinterpret_cast<QMouseEvent*>(event);
                if (mouseEvent->button() == Qt::LeftButton)
                {
                    if (!button->menu() || mouseEvent->pos().x() < button->width() - 20)
                    {
                        button->click();
                        return true;
                    }
                }
            }
        }
        return QObject::eventFilter(obj, event);
    }

private:
    QToolButton *button;
};


#endif // CLICKPOSITIONFILTER_H
