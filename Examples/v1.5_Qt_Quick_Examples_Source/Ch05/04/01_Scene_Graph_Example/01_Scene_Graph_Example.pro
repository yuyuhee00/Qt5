QT       += quick
HEADERS   = triangleitem.h
RESOURCES = resources.qrc
SOURCES   = main.cpp triangleitem.cpp

# own in Qt Creator.
qml.files += $$files(*.qml)
qml.path = "."
INSTALLS += qml
