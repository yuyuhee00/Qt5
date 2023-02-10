#include "client.h"

Client::Client(QObject *parent, QString name) : QObject(parent)
{
    setObjectName(name);
}

void Client::testing()
{
     for(int i = 0; i < 10; i++)
     {
         emit test(QString::number(i));
     }
}
