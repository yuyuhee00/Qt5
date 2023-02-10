#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QWaitCondition>
#include <QMutex>
#include <QThread>

static QMutex mutex;
static QWaitCondition incNumber;
static int numUsed;

class Producer : public QThread
{
    Q_OBJECT

    void run() override {
        for(int i = 0 ; i < 10 ; i++) {
            sleep(1);
            ++numUsed;
            qDebug("[Producer] numUsed : %d", numUsed);

            mutex.lock();
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
    void run() override {
        for(int i = 0 ; i < 10 ; i++) {
            mutex.lock();
            incNumber.wait(&mutex);
            mutex.unlock();

            qDebug("[Consumer] numUsed : %d", numUsed);
        }
    }

public:
    Consumer() { }
};

#endif // MYTHREAD_H
