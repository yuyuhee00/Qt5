
QT       += core gui

TARGET = 01_MDIMainWindow
TEMPLATE = app

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += main.cpp\
        mainwindow.cpp \
    MDIMainwindow.cpp

HEADERS  += mainwindow.h \
    MDIMainwindow.h

RESOURCES += \
    resources.qrc
    #res.qrc
