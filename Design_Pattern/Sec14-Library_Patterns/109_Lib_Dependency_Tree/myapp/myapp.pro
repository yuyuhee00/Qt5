QT -= gui
QT += network

CONFIG += c++14 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../build-Design_Pattern-Desktop_x86_darwin_generic_mach_o_64bit-Debug/Sec14-Library_Patterns/109_Lib_Dependency_Tree/downloader/release/ -ldownloader.1.0.0
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../build-Design_Pattern-Desktop_x86_darwin_generic_mach_o_64bit-Debug/Sec14-Library_Patterns/109_Lib_Dependency_Tree/downloader/debug/ -ldownloader.1.0.0
else:unix: LIBS += -L$$PWD/../../../../build-Design_Pattern-Desktop_x86_darwin_generic_mach_o_64bit-Debug/Sec14-Library_Patterns/109_Lib_Dependency_Tree/downloader/ -ldownloader.1.0.0

INCLUDEPATH += $$PWD/../../../../build-Design_Pattern-Desktop_x86_darwin_generic_mach_o_64bit-Debug/Sec14-Library_Patterns/109_Lib_Dependency_Tree/downloader
DEPENDPATH += $$PWD/../../../../build-Design_Pattern-Desktop_x86_darwin_generic_mach_o_64bit-Debug/Sec14-Library_Patterns/109_Lib_Dependency_Tree/downloader
