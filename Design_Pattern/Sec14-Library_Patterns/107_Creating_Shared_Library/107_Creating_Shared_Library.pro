TEMPLATE = subdirs

# build the project sequentially as listed in SUBDIRS !
CONFIG += ordered
CONFIG += ordered
CONFIG += sdk_no_version_check

SUBDIRS += \
    uploader \
    myapp
