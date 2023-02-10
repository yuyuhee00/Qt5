QT += core gui opengl

TARGET = 01_SimpleOpenGL

TEMPLATE = app

CONFIG += sdk_no_version_check

SOURCES += main.cpp\
           glwidget.cpp

HEADERS += glwidget.h

OTHER_FILES += fragmentShader.fsh\
               vertexShader.vsh

RESOURCES += resources.qrc
