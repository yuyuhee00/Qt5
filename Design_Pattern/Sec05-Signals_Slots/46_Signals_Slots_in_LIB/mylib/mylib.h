#ifndef MYLIB_H
#define MYLIB_H

#include "mylib_global.h"
#include <QObject>
#include <QTimer>
#include <QTime>

class MYLIB_EXPORT Mylib : public QObject
{
    Q_OBJECT

public:
    explicit Mylib(QObject *parent = nullptr);

signals:
    void started();
    void stopped();
    void triggered(QString value);

public slots:
    void start();
    void stop();

private slots:
    void timeout();

private:
    QTimer m_timer;
};

#endif // MYLIB_H
