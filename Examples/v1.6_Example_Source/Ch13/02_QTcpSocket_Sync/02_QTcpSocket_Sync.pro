QT       += core
QT       += network
QT       -= gui

TARGET = 02_QTcpSocket_Sync
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    qhttpsocket.cpp

HEADERS += \
    qhttpsocket.h
