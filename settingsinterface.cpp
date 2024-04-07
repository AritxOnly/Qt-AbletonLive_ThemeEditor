#include "settingsinterface.h"
#include "themeeditor.h"
#include "ui_settingsinterface.h"

SettingsInterface::SettingsInterface(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::SettingsInterface)
{

    ui->setupUi(this);
    ui->opacitySlider->setValue(reinterpret_cast<ThemeEditor*>(parent)->windowOpacity);
    connect(ui->opacitySlider,&QSlider::sliderMoved,reinterpret_cast<ThemeEditor*>(parent),&ThemeEditor::OpacityChanged);

}

SettingsInterface::~SettingsInterface()
{

}
