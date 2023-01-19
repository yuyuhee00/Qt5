QT       += core websockets
QT       -= gui

TARGET = 01_Chat_Example
CONFIG   += console
CONFIG   -= app_bundle
CONFIG += sdk_no_version_check

TEMPLATE = app

SOURCES += \
    main.cpp \
    chatserver.cpp

HEADERS += \
    chatserver.h


