TEMPLATE = subdirs

SUBDIRS += \
    downloader \
    myapp

myapp.depends += downloader
