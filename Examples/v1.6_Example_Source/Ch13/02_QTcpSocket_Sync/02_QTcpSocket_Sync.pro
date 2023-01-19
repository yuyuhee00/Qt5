QT       += core
QT       += network
QT       -= gui

TARGET = 02_QTcpSocket_Sync
CONFIG   += console
CONFIG   -= app_bundle
CONFIG += sdk_no_version_check

TEMPLATE = app


SOURCES += main.cpp \
    qhttpsocket.cpp

HEADERS += \
    qhttpsocket.h
