#include "Person.h"

Person::Person()
{
    name = nameList[next++];
}

QString Person::getName() const
{
    return name;
}

void Person::setName(const QString &newName)
{
    name = newName;
}

QString Person::nameList [] = { "Tom", "Dick", "Harry", "Bubba" };
int Person::next = 0;

