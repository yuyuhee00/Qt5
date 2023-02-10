TEMPLATE = subdirs

SUBDIRS += \
    mylib \
    myapp

myapp.depends = mylib

