TEMPLATE = subdirs

CONFIG += sdk_no_version_check

SUBDIRS += \
    mylib \
    myapp

myapp.depends = mylib

