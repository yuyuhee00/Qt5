#ifndef ALARM_H
#define ALARM_H

#include <QObject>
#include <QDebug>
#include <QTime>
#include <QTimer>

class Alarm : public QObject
{
    Q_OBJECT
public:
    explicit Alarm(QObject *parent = nullptr);
    ~Alarm();

    QTime limit() const;
    void setLimit(const QTime &limit);

public slots:
    void timeout();

signals:

private:
    QTime m_limit;
};

#endif // ALARM_H
