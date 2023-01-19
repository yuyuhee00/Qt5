
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 07_ScaledImageRender
TEMPLATE = app

CONFIG += sdk_no_version_check


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

FORMS    += widget.ui

RESOURCES += \
    resource.qrc
