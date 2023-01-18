
QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ChatServer
TEMPLATE = app

SOURCES += main.cpp\
        widget.cpp \
    chatserver.cpp

HEADERS  += widget.h \
    chatserver.h

FORMS    += widget.ui
