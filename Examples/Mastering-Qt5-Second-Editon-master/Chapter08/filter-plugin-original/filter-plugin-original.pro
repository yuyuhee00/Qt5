#-------------------------------------------------
#
# Project created by QtCreator 2016-06-23T12:16:33
#
#-------------------------------------------------

QT       += core widgets

TARGET = $$qtLibraryTarget(filter-plugin-original)
TEMPLATE = lib
CONFIG += plugin
CONFIG   += sdk_no_version_check

SOURCES += \
    FilterOriginal.cpp

HEADERS += \
    FilterOriginal.h

include(../plugins-common.pri)
