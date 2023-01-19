QT       += quick

HEADERS   = ellipseitem.h
RESOURCES = resources.qrc
SOURCES   = main.cpp ellipseitem.cpp

qml.files += $$files(*.qml)
qml.path = "."

INSTALLS += qml
