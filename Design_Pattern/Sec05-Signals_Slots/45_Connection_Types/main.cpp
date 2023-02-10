/*

  What
  Signal & Slot Connection Types

  Description
  Connections between signals and slots can have differnt connection types

  Why
    We are about to find out!

  Example

  https://doc.qt.io/qt-5/signalsandslots.html
  https://doc.qt.io/qt-5/qt.html#ConnectionType-enum

 */

#include <QCoreApplication>
#include <QDebug>
#include <QThread>
#include "myclass.h"

/*
 *
Qt::ConnectionType::AutoConnection (Default)
    - If the receiver lives in the thread that emits the signal, Qt::DirectConnection is used.
      Otherwise, Qt::QueuedConnection is used.
    - The connection type is determined when the signal is emitted.

Qt::ConnectionType::DirectConnection
    - The slot is invoked immedkiately when the signal is emmitted. The shot is executed in the signalling thread.

Qt::ConnectionType::QueuedConnection
    - The slot is invoked when control returns to the event loop of the receiver's therad. The slot is executed
      in the receiver's thread.

Qt::ConnectionType::BlockingQueuedConnection
    - Same as Qt::QueuedConnection, except that the signalling thread blocks until the slot returns.
      This connection must not be used if the receiver lives in the signalling thread, or else the application
      will deadlock.

Qt::ConnectionType::UniqueConnection
    - This is a flat that can be combined with any one of the above connection types, using a bitwise OR.
      When Qt::UniqueConnection is set, QObject::connect() will fail if the connection already exists
      (i,e. if the same signal is already connected to the same slot for the same pair of objects).
    - This flag was introduced in Qt 4.6

*/

void test(MyClass *source, MyClass *destination, Qt::ConnectionType type = Qt::ConnectionType::AutoConnection, QThread *thread = nullptr)
{
    QObject::connect(source, &MyClass::test, destination, &MyClass::onTest, type);
    if(thread)
    {
        qInfo() << &destination << "moving to:" << thread;
        destination->moveToThread(thread);
    }
    source->perform();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyClass source(nullptr,"source");
    MyClass destination(nullptr,"destination");

    QThread::currentThread()->setObjectName("Main Thread");

    QThread thread;
    thread.start();
    thread.setObjectName("Seperate Thread");


    ////////////////////////
    // ---Non-Threaded--- //
    ////////////////////////

    // Auto
    //test(&source, &destination);

    // DirectConnection
    //test(&source, &destination,Qt::DirectConnection);

    // QueuedConnection
    //test(&source,&destination,Qt::QueuedConnection);

    // BlockingQueuedConnection - will deadlock
    //test(&source,&destination,Qt::BlockingQueuedConnection);

    // UniqueConnection
    //test(&source,&destination,Qt::UniqueConnection);


    ////////////////////
    // ---Threaded--- //
    ////////////////////

    // Auto threaded - works across thread - sometimes
    //test(&source,&destination,Qt::AutoConnection, &thread);

    // DirectConnection threaded - signal triggers slot but sender is 0x0
    //test(&source,&destination,Qt::DirectConnection, &thread);

    // QueuedConnection threaded -  works as expected (perfered for cross thread)
    //test(&source,&destination,Qt::QueuedConnection, &thread);

    // BlockingQueuedConnection threaded - a bit dangerous, can lock the signaling thread
    //test(&source,&destination,Qt::BlockingQueuedConnection, &thread);

    // UniqueConnection threaded - works as expected
    test(&source, &destination, Qt::UniqueConnection, &thread);

    return a.exec();
}
