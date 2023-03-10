#include "pluginone.h"

PluginOne::PluginOne(QObject *parent)
{
    Q_UNUSED(parent);
    qInfo() << this << "created";
}

QString PluginOne::name()
{
    return QString("Plugin One");
}

QStringList PluginOne::commands()
{
    // list of supported commands
    QStringList list;

    list << "kittens";
    list << "cats";
    list << "lions";
    list << "tigers";

    return list;
}

void PluginOne::execute(QString command, QStringList args)
{
//    Q_UNUSED(args);
    QStringList list = commands();
    if(list.contains(command))
    {
        qInfo() << this << "execute" << command << args;
    }
}

QString PluginOne::GetIID()
{
    return iPluginOne_IID;
}

QTcpSocket *PluginOne::socket() const
{
    return m_socket;
}

void PluginOne::setSocket(QTcpSocket *socket)
{
    m_socket = socket;
}
