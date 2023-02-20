#ifndef PLUGINONE_H
#define PLUGINONE_H

/*
 *
 Low level API
 https://doc.qt.io/qt-5/plugins-howto.html


 Make a lib
 Remove the header
 Inherit QObject
 Inherit iPlugin
 Add the Q_PLUGIN_METADATA(IID QGenericPluginFactoryInterface_iid FILE "cats.json")


 *** Caller app doesn't care about dependency tree of libraries used in plugin.

 *** Because we use a QObject we have the full power of Qt - signals, slots, etc

 */

#include <QObject>
#include <QDebug>
#include "../myapp/interfaces/iPlugin.h"

#include <QTcpSocket>

#define iPluginOne_IID "com.company.PluginOne"

class PluginOne : public QObject, public iPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID iPluginOne_IID)
    Q_INTERFACES(iPlugin)

public:
    explicit PluginOne(QObject *parent = nullptr);

signals:

public slots:

    // iPlugin interface
public:
    QString name() override;
    QStringList commands() override;
    void execute(QString command, QStringList args) override;
    QString GetIID()override;

public:
    QTcpSocket *socket() const;
    void setSocket(QTcpSocket *socket);

private:
    QTcpSocket *m_socket;
};

#endif // PLUGINONE_H
