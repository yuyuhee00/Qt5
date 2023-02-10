QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 06_ChatClient
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11
CONFIG += sdk_no_version_check

SOURCES += \
        main.cpp \
        widget.cpp \
    loginwidget.cpp

HEADERS += \
        widget.h \
    loginwidget.h

FORMS += \
        widget.ui \
    loginwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
