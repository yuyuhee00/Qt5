/*
 *
 What
 Running QProcess from QML

 Description
 QML is a graphical layer and has all of Qt available

 Why
 QML is the way most applications will be created in the future

 Example
 QML and QProcess
 Another simple example:
 http://www.xargs.com/qml/process.html

 */

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "task.h"

int main(int argc, char *argv[])
{
//    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<Task>("com.company.task",1,0,"Task");

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
