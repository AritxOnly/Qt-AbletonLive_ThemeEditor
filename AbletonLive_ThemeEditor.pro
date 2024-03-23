QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    pugixml.cpp \
    themeeditor.cpp

HEADERS += \
    pugiconfig.hpp \
    pugixml.hpp \
    themeeditor.h

FORMS += \
    themeeditor.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

# 编译后应用图标设置
RC_FILE += \
    resource/logo.rc

# 编译后生成exe名称设置
TARGET = LiveThemeEditor
