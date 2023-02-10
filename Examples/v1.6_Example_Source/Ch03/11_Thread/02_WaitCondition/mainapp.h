#include <QCoreApplication>
#include <QWaitCondition>
#include <QMutex>
#include <QThread>

extern QMutex mutex;
extern QWaitCondition incNumber;
extern int numUsed;

class Producer : public QThread
{
    Q_OBJECT

    void run() override
    {
        for(int i = 0 ; i < 10 ; i++)
        {
            sleep(1);
            mutex.lock();
            ++numUsed;
            incNumber.wakeAll();
            mutex.unlock();
        }
    }

public:
    Producer() {}
};

class Consumer : public QThread
{
    Q_OBJECT
    void run() override
    {
        for(int i = 0 ; i < 10 ; i++)
        {
            mutex.lock();
                incNumber.wait(&mutex);
            mutex.unlock();

            qDebug("numUsed : %d", numUsed);
        }
    }

public:
    Consumer() { }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Producer producer;
    Consumer consumer;
    producer.start();
    consumer.start();

    return a.exec();
}
