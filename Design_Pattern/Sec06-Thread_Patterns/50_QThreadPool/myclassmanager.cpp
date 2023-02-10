#include "myclassmanager.h"
#include "myclass.h"

MyClassManager::MyClassManager(QObject *parent) : QObject(parent)
{

}

void MyClassManager::run()
{
    qInfo() << "Max Threads" << QThreadPool::globalInstance()->maxThreadCount();
    for(int  i = 0; i < 25; i++)
    {
        // No parent - on main thread
        MyClass *myclass = new MyClass(nullptr);

        // true will cause issues in this video
        // - myclass will be deleted before finished slot is called
        // - we have to manage the memory by ourself, when we are using signal/slot
        myclass->setAutoDelete(false);

        myclass->setObjectName("MyClass" + QString::number(i));

        connect(myclass, &MyClass::started, this, &MyClassManager::started, Qt::QueuedConnection);
        connect(myclass, &MyClass::progress, this, &MyClassManager::progress, Qt::QueuedConnection);
        connect(myclass, &MyClass::finished, this, &MyClassManager::finished, Qt::QueuedConnection);

        // The apps global thread pool
        QThreadPool::globalInstance()->start(myclass);
    }
}

void MyClassManager::started()
{
    MyClass *myclass = qobject_cast<MyClass*>(sender());
    if(!myclass) return;

    // This is on the main thread!
    qInfo() << myclass << "Started slot" << QThread::currentThread();
}

void MyClassManager::finished()
{
    MyClass *myclass = qobject_cast<MyClass*>(sender());
    if(!myclass) return;

    // This is on the main thread!
    qInfo() << myclass << "Finished slot" << QThread::currentThread();

    // Done with our object
    // - on the main thread
    myclass->deleteLater();
}

void MyClassManager::progress(int value)
{
    MyClass *myclass = qobject_cast<MyClass*>(sender());
    if(!myclass) return;

    // This is on the main thread!
    qInfo() << myclass << "Progress slot" << value << QThread::currentThread();
}
