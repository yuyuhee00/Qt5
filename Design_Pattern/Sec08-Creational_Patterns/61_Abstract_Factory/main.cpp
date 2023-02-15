/*

  What
  Creational - Abstract Factory

  Description
  Create related items without specifying a concrete class
  - C++ has no built-in concepts of interfaces. You can implement it using abstract classes which contains
    only pure virtual functions.

  Why
  Future proof the application

  Example
  "Think of constructors as factories that churn out objects".
  https://sourcemaking.com/design_patterns/abstract_factory

 */

#include <QCoreApplication>
#include <QDebug>
#include <QRandomGenerator>
#include "cats/catfactory.h"
#include "interfaces/iAnimal.h"

void makeAnimals(QList<iAnimal*> &animals, int count)
{
    CatFactory factory;

    for(int i = 0; i < count; i++)
    {
        iAnimal* animal;
        int value = QRandomGenerator::global()->bounded(0, 3);

        switch (value) {
        case 0:
            animal = factory.createSmall();
            animals.append(animal);
            break;
        case 1:
            animal = factory.createMedium();
            animals.append(animal);
            break;
        case 2:
            animal = factory.createLarge();
            animals.append(animal);
            break;
        default:
            qInfo() << "OTHER";
        }
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<iAnimal*> animals;
    makeAnimals(animals, 25);

    foreach(iAnimal* animal, animals)
    {
        animal->eat();
        animal->sleep();
    }

    qDeleteAll(animals);
    animals.clear();

    return a.exec();
}
