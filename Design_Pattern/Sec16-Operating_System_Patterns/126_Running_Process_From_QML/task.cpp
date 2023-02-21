#include "task.h"
#include <QDebug>
#include <windows.h>

Task::Task(QObject *parent) : QProcess(parent)
{
//    connect(this, &QProcess::readyReadStandardOutput, this, &Task::readyReadStandardOutput);
//    connect(this, &QProcess::readyRead, this, &Task::readyRead);
}

void Task::start(const QString &program, const QVariantList &arguments)
{
    QStringList args;
    for(int i = 0; i < arguments.length(); i++)
    {
        args << arguments[i].toString();
    }
//    QProcess::start(program, args);

    args.push_front(program);
    QProcess::start("cmd", args);
}

QString Task::readAll()
{
    qInfo() << "readAll()" ;
    QByteArray data = QProcess::readAll().trimmed();
    return QString::fromLocal8Bit(data);
}

QString Task::readyReadStandardOutput()
{
    qInfo() << "readyReadStandardOutput()" ;
    QByteArray data =  QProcess::readAllStandardOutput();
    return QString::fromLocal8Bit(data);
}
