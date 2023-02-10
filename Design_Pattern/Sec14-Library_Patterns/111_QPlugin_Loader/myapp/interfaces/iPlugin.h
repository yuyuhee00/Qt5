#ifndef IPLUGIN_H
#define IPLUGIN_H

#include <QString>
#include <QStringList>
#include <QtPlugin>

class iPlugin
{

public:
    virtual ~iPlugin() {} //this will make people mad

    virtual QString name() = 0;
    virtual QStringList commands() = 0;
    virtual void execute(QString command, QStringList args) = 0;
};

// Declare an interface that we can use
#define iInterface_IID "com.company.iPlugin/1.0"
Q_DECLARE_INTERFACE(iPlugin, iInterface_IID)

#endif // IPLUGIN_H
