#include <QCoreApplication>

/*

  What
  Encapsulation - really what we are talking about

  Description:
  Encapsulation is a process of combining data members and functions in a single unit called class.
  This is to prevent the access to the data directly, the access to them is provided through the
  functions of the class. It is one of the popular feature of Object Oriented Programming(OOPs)
  that helps in data hiding

  Why:
  Data security, private members should stay private!


 */

#include <QTextStream>
#include <QDebug>
#include "counter.h"

void userInput()
{
    qInfo() << "Enter a number:";
    QTextStream stream(stdin);
    QString data = stream.readLine();

    bool ok;
    int max = data.toInt(&ok);
    if(!ok)
    {
        qInfo() << "Not a number!";
        userInput();
        return;
    }

    Counter counter;
    counter.count(max);

    // counter.m_max = 12;
    // counter.performcount();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    userInput();
    return a.exec();
}
