/*
 *
 What
 Data Class

 Description
 Encapulate the IO in a class rather than spreading it across the application
 Also move all IO to a seperate thread
 SLOW IO should not lock up the GUI

 Why
 Easier to solve problems when we use the class
 We could see issues in the GUI if we don't puch IO to another thread!

 Example
 Basic Class
 QT += concurrent

 */

#include <QCoreApplication>
#include "animal.h"
#include <QDateTime>
#include <QDebug>
#include <QThread>

void saveAsync(QString path)
{
    qInfo() << "Saving a puppy";
    Animal dog;
    dog.setAge(12);
    dog.setFed(QDateTime::currentDateTime().addDays(-1));
    dog.setName("Rango");
    dog.setSpecies("dog");

    qInfo() << QThread::currentThread();

    dog.toFile(path);

    //Do other things here...

    dog.waitForFinished(); //Because we are on the command line, wait for finished
}

void loadAsync(QString path)
{
    qInfo() << "Loading puppy";
    Animal dog;
    dog.fromFile(path);


    qInfo() << QThread::currentThread();
    //Do other things here...

    dog.waitForFinished(); //Because we are on the command line, wait for finished

    qInfo() << "Name: " << dog.name();
    qInfo() << "Species: " << dog.species();
    qInfo() << "Age: " << dog.age();
    qInfo() << "Fed: " << dog.fed();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("main thread");

    QString path = "dog.txt";

    saveAsync(path);
    loadAsync(path);

    return a.exec();
}
