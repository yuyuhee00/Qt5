#-------------------------------------------------
#
# Project created by QtCreator 2016-06-23T12:16:33
#
#-------------------------------------------------

QT       += core widgets

TARGET = $$qtLibraryTarget(filter-plugin-blur)
TEMPLATE = lib
CONFIG += plugin
CONFIG   += sdk_no_version_check

SOURCES += \
    FilterBlur.cpp

HEADERS += \
    FilterBlur.h

include(../plugins-common.pri)
include(../plugins-common-opencv.pri)
