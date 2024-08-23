/********************************************************************************
** Form generated from reading UI file 'themeeditor.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THEMEEDITOR_H
#define UI_THEMEEDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ThemeEditor
{
public:
    QWidget *mainWidget;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *basicLayout;
    QWidget *topBar;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *openFolderButton;
    QLabel *currentTheme;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *settingsButton;
    QPushButton *helpButton;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *listWithButton;
    QListView *themeList;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *importExport;
    QSpacerItem *horizontalSpacer;
    QToolButton *saveSaveAs;
    QSpacerItem *horizontalSpacer_3;
    QWidget *demoArea;
    QHBoxLayout *demoLayout;

    void setupUi(QMainWindow *ThemeEditor)
    {
        if (ThemeEditor->objectName().isEmpty())
            ThemeEditor->setObjectName("ThemeEditor");
        ThemeEditor->resize(1500, 750);
        ThemeEditor->setStyleSheet(QString::fromUtf8("background-color: #2a2a2a;"));
        mainWidget = new QWidget(ThemeEditor);
        mainWidget->setObjectName("mainWidget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mainWidget->sizePolicy().hasHeightForWidth());
        mainWidget->setSizePolicy(sizePolicy);
        mainWidget->setLayoutDirection(Qt::LeftToRight);
        mainWidget->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(mainWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        basicLayout = new QVBoxLayout();
        basicLayout->setSpacing(0);
        basicLayout->setObjectName("basicLayout");
        topBar = new QWidget(mainWidget);
        topBar->setObjectName("topBar");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(topBar->sizePolicy().hasHeightForWidth());
        topBar->setSizePolicy(sizePolicy1);
        topBar->setMinimumSize(QSize(0, 35));
        topBar->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        topBar->setStyleSheet(QString::fromUtf8("background-color: #505050;\n"
"color:#c0c0c3"));
        horizontalLayout_3 = new QHBoxLayout(topBar);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        openFolderButton = new QPushButton(topBar);
        openFolderButton->setObjectName("openFolderButton");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(openFolderButton->sizePolicy().hasHeightForWidth());
        openFolderButton->setSizePolicy(sizePolicy2);
        openFolderButton->setMinimumSize(QSize(20, 20));
        openFolderButton->setStyleSheet(QString::fromUtf8("border-radius:10px;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/pics/resources/pics/file-open.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        openFolderButton->setIcon(icon);
        openFolderButton->setIconSize(QSize(20, 20));

        horizontalLayout_3->addWidget(openFolderButton);

        currentTheme = new QLabel(topBar);
        currentTheme->setObjectName("currentTheme");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(currentTheme->sizePolicy().hasHeightForWidth());
        currentTheme->setSizePolicy(sizePolicy3);
        currentTheme->setMinimumSize(QSize(200, 0));
        QFont font;
        font.setPointSize(12);
        currentTheme->setFont(font);
        currentTheme->setStyleSheet(QString::fromUtf8("color:#a0a0a2;"));

        horizontalLayout_3->addWidget(currentTheme);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        settingsButton = new QPushButton(topBar);
        settingsButton->setObjectName("settingsButton");
        sizePolicy2.setHeightForWidth(settingsButton->sizePolicy().hasHeightForWidth());
        settingsButton->setSizePolicy(sizePolicy2);
        settingsButton->setMinimumSize(QSize(25, 25));
        settingsButton->setStyleSheet(QString::fromUtf8("border-radius:10px;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/pics/resources/pics/setting.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        settingsButton->setIcon(icon1);
        settingsButton->setIconSize(QSize(20, 20));

        horizontalLayout_3->addWidget(settingsButton);

        helpButton = new QPushButton(topBar);
        helpButton->setObjectName("helpButton");
        sizePolicy2.setHeightForWidth(helpButton->sizePolicy().hasHeightForWidth());
        helpButton->setSizePolicy(sizePolicy2);
        helpButton->setMinimumSize(QSize(20, 20));
        helpButton->setStyleSheet(QString::fromUtf8("border-radius:10px;"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/pics/resources/pics/help-filling.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        helpButton->setIcon(icon2);
        helpButton->setIconSize(QSize(20, 20));

        horizontalLayout_3->addWidget(helpButton);


        basicLayout->addWidget(topBar);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        listWithButton = new QVBoxLayout();
        listWithButton->setObjectName("listWithButton");
        themeList = new QListView(mainWidget);
        themeList->setObjectName("themeList");
        QPalette palette;
        QBrush brush(QColor(192, 192, 195, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(50, 50, 50, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush2(QColor(106, 106, 106, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        QBrush brush3(QColor(192, 192, 195, 128));
        brush3.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush3);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        QBrush brush4(QColor(255, 255, 255, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush5(QColor(89, 89, 89, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush5);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush3);
#endif
        themeList->setPalette(palette);
        themeList->setAutoFillBackground(false);
        themeList->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"color:#c0c0c3;\n"
"background-color:#323232"));
        themeList->setEditTriggers(QAbstractItemView::NoEditTriggers);

        listWithButton->addWidget(themeList);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(10, 5, 10, 5);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        importExport = new QToolButton(mainWidget);
        importExport->setObjectName("importExport");
        sizePolicy3.setHeightForWidth(importExport->sizePolicy().hasHeightForWidth());
        importExport->setSizePolicy(sizePolicy3);
        importExport->setMinimumSize(QSize(100, 30));
        importExport->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"color:#c0c0c3;\n"
"background-color:#303032;\n"
"font-size:15px;"));
        importExport->setPopupMode(QToolButton::InstantPopup);
        importExport->setToolButtonStyle(Qt::ToolButtonIconOnly);

        horizontalLayout->addWidget(importExport);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        saveSaveAs = new QToolButton(mainWidget);
        saveSaveAs->setObjectName("saveSaveAs");
        sizePolicy3.setHeightForWidth(saveSaveAs->sizePolicy().hasHeightForWidth());
        saveSaveAs->setSizePolicy(sizePolicy3);
        saveSaveAs->setMinimumSize(QSize(100, 30));
        saveSaveAs->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"color:#c0c0c3;\n"
"background-color:#303032;\n"
"font-size:15px;"));
        saveSaveAs->setPopupMode(QToolButton::InstantPopup);

        horizontalLayout->addWidget(saveSaveAs);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(2, 2);
        horizontalLayout->setStretch(4, 1);

        listWithButton->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(listWithButton);

        demoArea = new QWidget(mainWidget);
        demoArea->setObjectName("demoArea");
        demoLayout = new QHBoxLayout(demoArea);
        demoLayout->setObjectName("demoLayout");

        horizontalLayout_2->addWidget(demoArea);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 4);

        basicLayout->addLayout(horizontalLayout_2);


        verticalLayout->addLayout(basicLayout);

        ThemeEditor->setCentralWidget(mainWidget);

        retranslateUi(ThemeEditor);

        QMetaObject::connectSlotsByName(ThemeEditor);
    } // setupUi

    void retranslateUi(QMainWindow *ThemeEditor)
    {
        ThemeEditor->setWindowTitle(QCoreApplication::translate("ThemeEditor", "ThemeEditor", nullptr));
        openFolderButton->setText(QString());
        currentTheme->setText(QCoreApplication::translate("ThemeEditor", "NoTheme", nullptr));
        settingsButton->setText(QString());
        helpButton->setText(QString());
        importExport->setText(QCoreApplication::translate("ThemeEditor", "...", nullptr));
        saveSaveAs->setText(QCoreApplication::translate("ThemeEditor", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ThemeEditor: public Ui_ThemeEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THEMEEDITOR_H
