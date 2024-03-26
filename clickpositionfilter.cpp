#include "clickpositionfilter.h"

ClickPositionFilter::ClickPositionFilter(QToolButton *button) : QObject(button), button(button)
{
}


bool ClickPositionFilter::eventFilter(QObject *obj, QEvent *event)
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
                    button->clicked();
                    return true;
                }
            }
        }
    }
    return QObject::eventFilter(obj, event);
}
