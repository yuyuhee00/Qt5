#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>
#include <QDebug>

class MyClass : public QObject
{
    Q_OBJECT

public:
    explicit MyClass(QObject *parent = nullptr);
    ~MyClass();

//    MyClass(MyClass const&) = delete;
//    MyClass& operator=(MyClass const&) = delete;
//    MyClass(MyClass const&&) = delete;
//    MyClass& operator=(MyClass const&&) = delete;

public:
    void test(QString value);

signals:

};

#endif // MYCLASS_H
