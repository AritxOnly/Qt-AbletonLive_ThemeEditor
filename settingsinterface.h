#ifndef SETTINGSINTERFACE_H
#define SETTINGSINTERFACE_H


#include "qheaders.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class SettingsInterface;
}
QT_END_NAMESPACE

class SettingsInterface : public QMainWindow
{
    Q_OBJECT
public:
    SettingsInterface(QWidget *parent = nullptr);
    ~SettingsInterface();

    void SliderMoved(int value);

private:
    Ui::SettingsInterface* ui;

};

#endif // SETTINGSINTERFACE_H
