QT       += core
QT       += network
QT       -= gui

TARGET = 01_QTcpSocket_SignalSlot_Example
CONFIG   += console
CONFIG   -= app_bundle
CONFIG += sdk_no_version_check

TEMPLATE = app


SOURCES += main.cpp \
    qhttpsocket.cpp

HEADERS += \
    qhttpsocket.h
