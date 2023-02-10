#include "interpreter.h"

Interpreter::Interpreter(QObject *parent) : QObject(parent)
{

}

int Interpreter::interpret(QString data)
{
    int value = 0;
    QByteArray bytes(data.toUtf8());
    bool ok;

    if(data.startsWith("0x"))
    {
        //convert from hex to dec
        value = bytes.toInt(&ok, 16);
        if(!ok) value = -1;
    }
    else
    {
        //convert from string to dec
        value = bytes.toInt(&ok, 10);
        if(!ok) value = -1;
    }

    return value;

}

