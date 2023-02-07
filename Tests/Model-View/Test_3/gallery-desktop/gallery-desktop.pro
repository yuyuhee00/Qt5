QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AlbumListWidget.cpp \
    AlbumWidget.cpp \
    GalleryWidget.cpp \
    PIctureDelegate.cpp \
    ThumbnailProxyModel.cpp \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    AlbumListWidget.h \
    AlbumWidget.h \
    GalleryWidget.h \
    MainWindow.h \
    PIctureDelegate.h \
    ThumbnailProxyModel.h

FORMS += \
    AlbumListWidget.ui \
    AlbumWidget.ui \
    GalleryWidget.ui \
    MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../gallery-core/release/ -lgallery-core
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../gallery-core/debug/ -lgallery-core
else:unix: LIBS += -L$$OUT_PWD/../gallery-core/ -lgallery-core

INCLUDEPATH += $$PWD/../gallery-core
DEPENDPATH += $$PWD/../gallery-core

RESOURCES += \
	res/resource.qrc
