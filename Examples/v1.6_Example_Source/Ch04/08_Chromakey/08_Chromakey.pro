
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 06_Chromakey_Complete
TEMPLATE = app

CONFIG += sdk_no_version_check


SOURCES += main.cpp\
        widget.cpp \
    imageprocessing.cpp

HEADERS  += widget.h \
    imageprocessing.h

FORMS    += widget.ui

RESOURCES += \
    resources.qrc
