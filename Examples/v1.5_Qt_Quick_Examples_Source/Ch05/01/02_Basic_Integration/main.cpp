#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>
#include <qqml.h>
#include "message.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQuickView viewer;
    Message msg;

    viewer.engine()->rootContext()->setContextProperty("msg", &msg);
    viewer.setSource( QUrl( "qrc:///main.qml" ) );

    return app.exec();
}
