#ifndef MACHINE_H
#define MACHINE_H

#include <QObject>
#include <QDebug>

class Machine : public QObject
{
    Q_OBJECT

public:
    explicit Machine(QObject *parent = nullptr);

    // Old way of solving the problem
    // void original() Q_DECL_DEPRECATED ;

    Q_DECL_DEPRECATED_X("Try the newCode function instead")
    void original();

    //New way of solving the problem
    void newCode();

signals:

};

#endif // MACHINE_H
