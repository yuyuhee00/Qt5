TEMPLATE = app

QT       += quick network widgets

HEADERS += \
    tcpconnection.h
SOURCES += main.cpp \
    tcpconnection.cpp

RESOURCES +=  resources.qrc

OTHER_FILES += $$files(*.qml)
