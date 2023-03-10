QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 02_Gui_App
TEMPLATE = app
DEFINES += QT_DEPRECATED_WARNINGS
CONFIG += c++11

SOURCES += \
        main.cpp \
        widget.cpp
HEADERS += \
        widget.h

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
