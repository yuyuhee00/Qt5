#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>
#include <QDebug>

class MyClass : public QObject
{
    Q_OBJECT

    // By design you can not copy or move a QObject
    // Q_DISABLE_COPY(MyClass);
    // Q_DISABLE_COPY_MOVE(MyClass);

public:
    explicit MyClass(QObject *parent = nullptr);
    ~MyClass();

    MyClass* clone() {
        auto copy = new MyClass;

        // Copy data only, not signals and slots
        return copy;
    }

signals:

};

#endif // MYCLASS_H
