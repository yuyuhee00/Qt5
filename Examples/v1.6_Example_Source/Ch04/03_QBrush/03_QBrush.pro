
QT       += core gui

TARGET = QBrush
TEMPLATE = app

CONFIG += sdk_no_version_check

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

RESOURCES += \
    resource.qrc
