#ifndef MACHINE_H
#define MACHINE_H

#include <QObject>
#include <QTimer>
#include <QDebug>

class Machine : public QObject
{
    Q_OBJECT

    // Properties can be used in QML
    Q_PROPERTY(int count READ count WRITE setCount NOTIFY countChanged) // getter, setter, signal
    Q_PROPERTY(int max READ max WRITE setMax NOTIFY maxChanged) // getter, setter, signal
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged) // getter, setter

public:
    explicit Machine(QObject *parent = nullptr);

    int count() const;
    void setCount(int count);

    int max() const;
//    void setMax(int max);

    QString name() const;
    void setName(const QString &name);

// signals can be connected to QML
signals:
    void started();
    void stopped();
    void paused();
    void maxChanged(int value);
    void countChanged(int value);
    void nameChanged(QString name);

// slots can be called in QML
public slots:
    void start();
    void stop();
    void pause();
    void setMax(int max);

private slots:
    void timeout();

private:
    int m_count;
    int m_max;
    QString m_name;

    QTimer m_timer;
};

#endif // MACHINE_H
