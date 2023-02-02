TEMPLATE = subdirs

# build the project sequentially as listed in SUBDIRS !
CONFIG += sdk_no_version_check

SUBDIRS += \
    uploader \
    myapp
myapp.depends += uploader
