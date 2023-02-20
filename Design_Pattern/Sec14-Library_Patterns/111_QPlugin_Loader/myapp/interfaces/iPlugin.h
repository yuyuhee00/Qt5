#ifndef IPLUGIN_H
#define IPLUGIN_H

#include <QString>
#include <QStringList>
#include <QtPlugin>


#define iPlugin_IID "com.company.iPlugin/1.0"

class iPlugin
{

public:
    virtual ~iPlugin() {} //this will make people mad

    virtual QString name() = 0;
    virtual QStringList commands() = 0;
    virtual void execute(QString command, QStringList args) = 0;

    virtual QString GetIID() { return iPlugin_IID; }
};

// Declare an interface that we can use
//#define iPlugin_IID "com.company.iPlugin/1.0"
Q_DECLARE_INTERFACE(iPlugin, iPlugin_IID)

#endif // IPLUGIN_H
