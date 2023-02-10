#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int myVal = 100;

    qDebug() << "Hello World.";
    qDebug("Qt First Project. My Value. %d", myVal);

    return a.exec();
}
