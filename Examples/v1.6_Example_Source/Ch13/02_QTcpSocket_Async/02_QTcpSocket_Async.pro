QT       += core
QT       += network
QT       -= gui

TARGET = 01_QTcpSocket_SignalSlot_Example
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    qhttpsocket.cpp

HEADERS += \
    qhttpsocket.h
