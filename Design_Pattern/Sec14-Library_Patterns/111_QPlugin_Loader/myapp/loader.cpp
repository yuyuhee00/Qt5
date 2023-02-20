#include "loader.h"
#include "interfaces/iPlugin.h"

Loader::Loader(QObject *parent) : QObject(parent)
{

}

Loader::~Loader()
{
    foreach(QPluginLoader* loader, m_plugins)
    {
        if(loader->isLoaded()) loader->unload();
    }

    qDeleteAll(m_plugins);
    m_plugins.clear();
}

void Loader::loadPlugins(QString path)
{
    // Could do something like search a folder for .so, .dll, .dylib - what ever your platform requires

    qInfo() << "Loading plugins:" << path;

    QDir dir(path);
    if(!dir.exists(path) && dir.isReadable())
    {
        qWarning() << "Plugin path does not exist!";
        return;
    }

    qInfo() << "CHECK:" << dir.absolutePath();

    QStringList filters;
    filters << "*.so" << "*.dll" << "*.dylib";

    // Need permissions to the folder or this will fail
    QFileInfoList files =  dir.entryInfoList(filters,QDir::Files | QDir::NoDotAndDotDot);//dir.entryList(filters,QDir::NoDotAndDotDot);

    foreach(QFileInfo file, files)
    {
        QPluginLoader *pl = new QPluginLoader(this);
        pl->setFileName(file.absoluteFilePath());
        if(! pl->load())
            qWarning() << file.fileName() << pl->errorString();
        m_plugins.append(pl);
    }

    // Show the loaded plugins
    qInfo() << "Loaded Plugins:";
    foreach(QPluginLoader *loader, m_plugins)
    {
        if(loader->isLoaded())
        {
            iPlugin *plugin = dynamic_cast<iPlugin*>(loader->instance());
            if(plugin)
            {
                qInfo() << "Name" << plugin->name();
                qInfo() << "Commands" << plugin->commands();
                qInfo() <<  "IID" << plugin->GetIID();
            }
        }
    }
}

void Loader::execute(QString command, QStringList args)
{
    qInfo() << "Execute Plugins...";
    foreach(QPluginLoader *loader, m_plugins)
    {
        if(loader->isLoaded())
        {
            iPlugin *plugin = dynamic_cast<iPlugin*>(loader->instance());
            if(plugin)
            {
                plugin->execute(command, args);
            }
        }
    }
}
