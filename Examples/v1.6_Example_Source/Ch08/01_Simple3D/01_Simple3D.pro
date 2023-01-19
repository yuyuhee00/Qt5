QT += core gui
QT += 3dcore 3drender 3dinput 3dextras

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 01_Simple3D
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS
CONFIG += c++11
CONFIG += sdk_no_version_check


SOURCES += \
        main.cpp \
        widget.cpp

HEADERS += \
        widget.h

FORMS += \
        widget.ui


