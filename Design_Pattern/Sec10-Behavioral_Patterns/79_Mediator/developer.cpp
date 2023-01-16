#include "developer.h"

Developer::Developer(QObject *parent) : QObject(parent)
{

}

void Developer::createPrograms()
{
    qInfo() << this << "Write code";
    qInfo() << this << "Testing";
    qInfo() << this << "Packaging";
    qInfo() << this << "Production release";

}
