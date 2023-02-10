TEMPLATE = subdirs

SUBDIRS += \
    bla \
    myapp

myapp.depends += bla
