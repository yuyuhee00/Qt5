QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CustomButton
TEMPLATE = app

CONFIG += sdk_no_version_check


SOURCES += main.cpp\
        widget.cpp \
    imagebutton.cpp

HEADERS  += widget.h \
    imagebutton.h

FORMS    += widget.ui

RESOURCES += \
    resources.qrc


