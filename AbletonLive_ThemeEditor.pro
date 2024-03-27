QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    clickpositionfilter.cpp \
    filehandler.cpp \
    main.cpp \
    settingsinterface.cpp \
    themedata.cpp \
    themeeditor.cpp

HEADERS += \
    clickpositionfilter.h \
    filehandler.h \
    qheaders.h \
    settingsinterface.h \
    themedata.h \
    themeeditor.h

FORMS += \
    settingsinterface.ui \
    themeeditor.ui

QMAKE_CXXFLAGS += -w
QMAKE_CFLAGS += -w

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

# 编译后应用图标设置
RC_FILE += \
    resources/icons/logo.rc

# 编译后生成exe名称设置
TARGET = AbletonLiveThemeEditor
