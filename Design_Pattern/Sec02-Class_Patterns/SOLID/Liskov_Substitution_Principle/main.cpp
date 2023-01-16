#include <QCoreApplication>

/*

 SOLID - https://en.wikipedia.org/wiki/SOLID
 Single Responsibility Principle
 Open/Closed Principle
 Liskov Substitution Principle
 Interface Segregation Principle
 Dependency Inversion Principle

 What
 Liskov Substitution Principle

 Define
 The principle defines that objects of a superclass shall be replaceable with objects of its subclasses without breaking the application
 - Objects in prgram should be replaceable with instances of their subtypes without altering the correctness of that program

 Why
 Extends the Open/Closed principle - replace objects of a parent class with objects of a subclass without breaking the application.

 Example
 QT += network
 TCP Sockets - its easy to break this, and hard to detect it.
 In short - a class and function should do what it says it will do

 */

#include <QDebug>
#include <QTcpSocket>
#include "mysocket.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //QTcpSocket socket;
    MySocket socket;

    qInfo() << "Connecting...";
    socket.connectToHost("voidrealms.com",80);
    socket.waitForConnected();

    qInfo() << "Connected";
    //do something while connected

    qInfo() << "Closing...";
    socket.close();
    if(socket.isOpen()) socket.waitForDisconnected();

    qInfo() << "Complete!";

    return a.exec();
}






