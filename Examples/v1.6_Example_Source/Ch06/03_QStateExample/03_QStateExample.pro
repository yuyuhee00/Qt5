
QT       += core gui

TARGET = 03_QStateExample
TEMPLATE = app

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h
