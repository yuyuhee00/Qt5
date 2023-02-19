TEMPLATE = subdirs

# build the project sequentially as listed in SUBDIRS !

SUBDIRS += \
    uploader \
    myapp
myapp.depends += uploader
