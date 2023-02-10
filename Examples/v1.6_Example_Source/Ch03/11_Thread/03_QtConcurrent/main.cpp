#include <QCoreApplication>

#include <QThread>
#include <QtConcurrent/QtConcurrent>
#include <QtConcurrent/QtConcurrentRun>

void hello(QString name)
{
    qDebug() << "Hello" << name << "from" << QThread::currentThread();

    for(int i = 0 ; i < 3 ; i++)
    {
        QThread::sleep(1);
        qDebug("[%s] i = %d", name.toLocal8Bit().data(), i);
    }
}

void world(QString name)
{
    qDebug() << "World" << name << "from" << QThread::currentThread();

    for(int i = 0 ; i < 3 ; i++)
    {
        QThread::sleep(1);
        qDebug("[%s] i = %d", name.toLocal8Bit().data(), i);
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    QFuture<void> f1 = QtConcurrent::run(hello, QString("Alice"));
    QFuture<void> f2 = QtConcurrent::run(hello, QString("Bob"));
    QFuture<void> f3 = QtConcurrent::run(hello, QString("Eddy"));

    f1.waitForFinished();
    f2.waitForFinished();
    f3.waitForFinished();

    return a.exec();
}


