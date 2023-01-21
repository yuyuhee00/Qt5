#include "machine.h"

Machine::Machine(QObject *parent) : QObject(parent)
{

}


void Machine::original()
{
//#warning Try the newCode function instead
//#pragma message("You might still see this even if you are not using visual studio") //Visual Studio
    qInfo() << "Orginal code here";
}

void Machine::newCode()
{
    qInfo() << "New code here";
}
