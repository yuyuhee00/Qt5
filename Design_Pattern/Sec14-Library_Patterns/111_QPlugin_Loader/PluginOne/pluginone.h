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

 because we use a QObject we have the full power of Qt - signals, slots, etc
 */

#include <QObject>
#include <QDebug>
#include "../myapp/interfaces/iPlugin.h"

class PluginOne : public QObject, public iPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.company.PluginOne")
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
};

#endif // PLUGINONE_H
