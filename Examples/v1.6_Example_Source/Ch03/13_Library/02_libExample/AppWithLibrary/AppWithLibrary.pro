QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AppWithLibrary
TEMPLATE = app

SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

FORMS    += widget.ui

LIBS += -L/Users/yuyuhee/Language/C++/Qt5/build-v1.6_Example_Source-Desktop_x86_darwin_generic_mach_o_64bit-Debug/Ch03/13_Library/02_libExample/MyUtil -lMyUtil

INCLUDEPATH += $$PWD/../MyUtil
DEPENDPATH += $$PWD/../MyUtil
