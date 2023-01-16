#include "chef.h"

Chef::Chef(QObject *parent) : QObject(parent)
{

}

void Chef::makeDinner()
{
    prepair();
    cook();
    cleanup();
}

void Chef::prepair()
{
    qInfo() << this << "prepair here";
}

void Chef::cook()
{
    qInfo() << this << "cook here";
}

void Chef::cleanup()
{
    qInfo() << this << "cleanup here";

}
