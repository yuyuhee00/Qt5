QT       += core websockets
QT       -= gui

TARGET = 01_Chat_Example
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += \
    main.cpp \
    chatserver.cpp

HEADERS += \
    chatserver.h


