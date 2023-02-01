TEMPLATE = subdirs

SUBDIRS += \
    PluginOne \
    myapp

myapp.depends = PluginOne
