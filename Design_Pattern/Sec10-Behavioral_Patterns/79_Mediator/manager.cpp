#include "manager.h"

Manager::Manager(QObject *parent) : QObject(parent)
{

}

void Manager::startProject()
{
    qInfo() << "Starting a project";
    emit getToWork();
}

void Manager::complete()
{
    qInfo() << sender() << "Complete";
}
