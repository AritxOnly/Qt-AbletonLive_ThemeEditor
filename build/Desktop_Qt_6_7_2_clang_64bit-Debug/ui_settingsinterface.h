/********************************************************************************
** Form generated from reading UI file 'settingsinterface.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSINTERFACE_H
#define UI_SETTINGSINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsInterface
{
public:
    QWidget *mainWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *opacityLayout;
    QLabel *opacityLabel;
    QSlider *opacitySlider;

    void setupUi(QMainWindow *SettingsInterface)
    {
        if (SettingsInterface->objectName().isEmpty())
            SettingsInterface->setObjectName("SettingsInterface");
        SettingsInterface->resize(400, 300);
        mainWidget = new QWidget(SettingsInterface);
        mainWidget->setObjectName("mainWidget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mainWidget->sizePolicy().hasHeightForWidth());
        mainWidget->setSizePolicy(sizePolicy);
        mainWidget->setStyleSheet(QString::fromUtf8("color:#c0c0c3;\n"
"\n"
"QSlider::groove:horizontal {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #B1B1B1, stop:1 #c4c4c4);\n"
"border: 1px solid #999999;\n"
"height: 8px;\n"
"border-radius: 4px;\n"
"}\n"
"QSlider::handle:horizontal {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #eeeeee, stop:1 #dddddd);\n"
"border: 1px solid #5c5c5c;\n"
"width: 18px;\n"
"margin: -2px 0;\n"
"border-radius: 4px;\n"
"}"));
        verticalLayout = new QVBoxLayout(mainWidget);
        verticalLayout->setObjectName("verticalLayout");
        opacityLayout = new QHBoxLayout();
        opacityLayout->setObjectName("opacityLayout");
        opacityLabel = new QLabel(mainWidget);
        opacityLabel->setObjectName("opacityLabel");

        opacityLayout->addWidget(opacityLabel);

        opacitySlider = new QSlider(mainWidget);
        opacitySlider->setObjectName("opacitySlider");
        opacitySlider->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #B1B1B1, stop:1 #c4c4c4);\n"
"border: 1px solid #999999;\n"
"height: 8px;\n"
"border-radius: 4px;\n"
"}\n"
"QSlider::handle:horizontal {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #eeeeee, stop:1 #dddddd);\n"
"border: 1px solid #5c5c5c;\n"
"width: 18px;\n"
"margin: -2px 0;\n"
"border-radius: 4px;\n"
"};"));
        opacitySlider->setMinimum(20);
        opacitySlider->setMaximum(100);
        opacitySlider->setSingleStep(0);
        opacitySlider->setValue(100);
        opacitySlider->setOrientation(Qt::Horizontal);

        opacityLayout->addWidget(opacitySlider);


        verticalLayout->addLayout(opacityLayout);

        SettingsInterface->setCentralWidget(mainWidget);

        retranslateUi(SettingsInterface);

        QMetaObject::connectSlotsByName(SettingsInterface);
    } // setupUi

    void retranslateUi(QMainWindow *SettingsInterface)
    {
        SettingsInterface->setWindowTitle(QCoreApplication::translate("SettingsInterface", "MainWindow", nullptr));
        opacityLabel->setText(QCoreApplication::translate("SettingsInterface", "Opacity", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsInterface: public Ui_SettingsInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSINTERFACE_H
