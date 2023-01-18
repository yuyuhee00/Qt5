QT += core gui multimedia widgets
CONFIG += c++14
CONFIG   += sdk_no_version_check

TARGET = drum-machine
TEMPLATE = app

include(../drum-machine-src.pri)

SOURCES += main.cpp
