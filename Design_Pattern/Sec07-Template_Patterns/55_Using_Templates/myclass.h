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

    // This does not work because QObject us not allowed to be copied
//    MyClass operator + (MyClass const &obj) {
//        MyClass res;
//        return res; //implicit-delted copy constructor
//    }

    int value() const;
    void setValue(int value);

signals:

private:
    int m_value;
};

#endif // MYCLASS_H
