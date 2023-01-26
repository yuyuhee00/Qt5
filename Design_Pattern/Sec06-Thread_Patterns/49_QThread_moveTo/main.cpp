/*

    What
    QObject moveto QThread

    Description
    Not the best idea but it can be done
    - It's better than inheritance from QThread class

    Why
    You do not want to risk breaking the functionality of QThread

    Example
    move an object to a thread

*/

#include <QCoreApplication>
#include <QObject>
#include <QTimer>
#include <QThread>
#include <QDebug>
#include "myclass.h"

QThread *thread;
QTimer *timer;
MyClass *myclass;

void timeout()
{
    if(!thread) return;
    if(!timer) return;

    if(thread->isRunning() == true && thread->isFinished() == false)
    {
        qInfo() << "Thread is Running...";
    }

    if(thread->isRunning() == false && thread->isFinished() == true)
    {
        qInfo() << "Thread is Finished!";
        timer->stop();

        thread->deleteLater();
        timer->deleteLater();
        myclass->deleteLater();
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("Main thread");
    thread = new QThread(&a);
    thread->setObjectName("Child thread");

    timer = new QTimer(&a);

    // NO PARENT!!!!
    // - Cann't move objects with parent
    //   myclass = new MyClass(&a);
    myclass = new MyClass(nullptr);

    QObject::connect(timer, &QTimer::timeout, timeout); //Auto connection
    QObject::connect(thread, &QThread::started, myclass, &MyClass::run, Qt::QueuedConnection); //cross thread signal / slot
    QObject::connect(myclass, &MyClass::finished, thread, &QThread::quit, Qt::QueuedConnection); //cross thread signal / slot

    // Will fail if there is a parent!
    // - This is better than inheritance from QThread class
    myclass->moveToThread(thread);

    timer->setInterval(1000);

    timer->start();
    thread->start(); //QThread::start calls QThread::run()

    //Do other things in the background

    return a.exec();
}
