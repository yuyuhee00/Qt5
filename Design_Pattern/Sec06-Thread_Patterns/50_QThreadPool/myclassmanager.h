#ifndef MYCLASSMANAGER_H
#define MYCLASSMANAGER_H

#include <QObject>
#include <QThreadPool>
#include <QRunnable>

class MyClassManager : public QObject
{
    Q_OBJECT

public:
    explicit MyClassManager(QObject *parent = nullptr);

public:
    void run();

signals:

public slots:
    void started();
    void finished();
    void progress(int value);
};

#endif // MYCLASSMANAGER_H
