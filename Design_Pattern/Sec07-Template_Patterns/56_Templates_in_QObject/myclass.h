#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>


class MyClass : public QObject
{
    Q_OBJECT
public:
    explicit MyClass(QObject *parent = nullptr);

    template<typename T>
    T add(T a, T b)
    {
        return a + b;
    }

signals:

};

#endif // MYCLASS_H
