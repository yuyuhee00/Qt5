#include "server.h"

Server::Server(QObject *parent) : QObject(parent)
{

}

void Server::connected()
{
    QObject *source = sender();
    qInfo() << this << "connected from" << source;
}

void Server::disconnected()
{
    QObject *source = sender();
    qInfo() << this << "disconnected from" << source;
}

void Server::readyRead()
{
    QObject *source = sender();
    qInfo() << this << "readyRead from" << source;
}

void Server::test(QString name)
{
    QObject *source = sender();
    qInfo() << this << "test from" << source << name;
}

void Server::internal()
{
    QObject *source = sender();
    qInfo() << this << "internal from" << source;
}

