#ifndef MEMENTO_H
#define MEMENTO_H

#include <QObject>

class Memento : public QObject
{
    Q_OBJECT

public:
    explicit Memento(QObject *parent = nullptr);

    void commit();
    void rollback();
    void cancel();

    void addTransaction(QString value);
    QString command();

signals:

private:
    QStringList m_commands;
    QString m_command;
};

#endif // MEMENTO_H
