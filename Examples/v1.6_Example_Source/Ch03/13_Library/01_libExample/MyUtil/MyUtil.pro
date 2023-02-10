QT       -= gui

TARGET = MyUtil
TEMPLATE = lib

DEFINES += MYUTIL_LIBRARY
DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        myutil.cpp

HEADERS += \
        myutil.h \
        myutil_global.h 

unix {
    target.path = /usr/lib
    INSTALLS += target
}
