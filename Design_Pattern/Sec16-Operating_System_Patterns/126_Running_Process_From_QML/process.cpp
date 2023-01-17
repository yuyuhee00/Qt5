#include "process.h"

Process::Process(QObject *parent) : QProcess(parent)
{

}

void Process::start(const QString &program, const QVariantList &arguments)
{
    QStringList args;
    for(int i = 0; i < arguments.length(); i++)
    {
        args << arguments[i].toString();
    }

    QProcess::start(program, args);
}

QByteArray Process::readAll()
{
    return QProcess::readAll();
}
