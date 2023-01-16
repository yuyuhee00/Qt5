#include "marketing.h"

Marketing::Marketing(QObject *parent) : QObject(parent)
{

}

void Marketing::createHype()
{
    qInfo() << this << "Make super cool videos on youtube";
    qInfo() << this << "Google ads";
    qInfo() << this << "Attend developer conferences";

    emit finished();
}
