
QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ChatServer
TEMPLATE = app

CONFIG += sdk_no_version_check

SOURCES += main.cpp\
        widget.cpp \
    chatserver.cpp

HEADERS  += widget.h \
    chatserver.h

FORMS    += widget.ui
