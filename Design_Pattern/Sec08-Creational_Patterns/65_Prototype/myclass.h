#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>
#include <QDebug>

#include "interfaces/icloneable.h"

class MyClass : public QObject, public iCloneable
{
    Q_OBJECT

public:
    explicit MyClass(QObject *parent = nullptr);

    QString firstname() const;
    void setFirstname(const QString &firstname);

    QString lastname() const;
    void setLastname(const QString &lastname);

    int age() const;
    void setAge(int age);

    void display();

signals:

private:
    QString m_firstname;
    QString m_lastname;
    int m_age;

    // iCloneable interface
public:
    QObject *clone() override;
};

#endif // MYCLASS_H
