QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AppWithLibrary
TEMPLATE = app

SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

FORMS    += widget.ui

#LIBS += -L$$PWD/../build-MyUtil-Desktop_Qt_5_12_2_MinGW_32_bit-Debug/debug/ -lMyUtil

LIBS += -L/Users/yuyuhee/Language/C++/Qt5/build-v1.6_Example_Source-Desktop_x86_darwin_generic_mach_o_64bit-Debug/Ch03/13_Library/01_libExample/MyUtil -lMyUtil

INCLUDEPATH += $$PWD/../MyUtil
DEPENDPATH += $$PWD/../MyUtil
