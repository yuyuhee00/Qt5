#include "basicradio.h"

BasicRadio::BasicRadio(QObject *parent) : QObject(parent)
{

}


void BasicRadio::play()
{
    qInfo() << this <<  "Playing music";
}

void BasicRadio::stop()
{
    qInfo() << this <<  "Stopping the music";
}
