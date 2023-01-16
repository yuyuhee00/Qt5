#include <QCoreApplication>

/*

 What:
 Access modifiers

 Description:
 Determines how members of the class can be accessed
 private, public, protected
 Qt adds signals and slots - we will cover those in greater detail later

 Why:
 Multiple reasons, design=, encapulation, data protection

 Example:
 Looking at QTCPServer
 QT += network

 */

#include <QDebug>
#include "myserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyServer server;
    int value = 0;
    if(server.listen(QHostAddress::Any, 3301))
    {
        qInfo() << "Listening";
        value = a.exec();
        server.close();

    }
    else
    {
        qWarning() << server.errorString();
    }

    return value;
}
