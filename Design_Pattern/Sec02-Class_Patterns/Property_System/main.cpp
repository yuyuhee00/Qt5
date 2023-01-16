#include <QGuiApplication>
#include <QQmlApplicationEngine>

/*

  What:
  Q_Property

  Description:
  Qt property system

  Why:
  Easy encapulation and uses the Qt property system

  Example:
  QML App, show how to add the c++ class, and how to access the property in both QML and C++


 */

#include <QDebug>
#include "machine.h"

//Properties in C++
void test()
{
    qInfo() << "Starting C++ test";

    Machine machine;
    machine.setMax(5);

    qInfo() << "Max = " << machine.max();
    machine.setProperty("name","Bryan");
    qInfo() << "Name = " << machine.name();
}


#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    //C++ test
    //test();

    qmlRegisterType<Machine>("com.company.machine",1,0,"Machine");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
