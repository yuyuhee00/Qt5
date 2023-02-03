#include "task.h"
#include <QDebug>
#include <windows.h>

Task::Task(QObject *parent) : QProcess(parent)
{
}

void Task::start(const QString &program, const QVariantList &arguments)
{
    QStringList args;
    for(int i = 0; i < arguments.length(); i++)
    {
        args << arguments[i].toString();
    }

    QProcess::start(program, args);
}

QString Task::readAll()
{
    QByteArray data = QProcess::readAll().trimmed();
    return QString::fromLocal8Bit(data);
}
