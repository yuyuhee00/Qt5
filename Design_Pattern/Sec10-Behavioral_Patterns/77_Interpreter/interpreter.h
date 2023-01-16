#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <QObject>
#include <QDebug>

class Interpreter : public QObject
{
    Q_OBJECT

public:
    explicit Interpreter(QObject *parent = nullptr);

    int interpret(QString data);

signals:

};

#endif // INTERPRETER_H
