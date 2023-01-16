#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>
#include <QDebug>


class Counter : public QObject
{
    Q_OBJECT

public:
    explicit Counter(QObject *parent = nullptr);

    void count(int max);

private:
    int m_count;
    int m_max;
    void performcount();

signals:

};

#endif // COUNTER_H
