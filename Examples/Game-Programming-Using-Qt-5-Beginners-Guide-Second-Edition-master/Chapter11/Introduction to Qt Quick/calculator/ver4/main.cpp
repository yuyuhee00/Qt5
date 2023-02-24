#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "advancedcalculator.h"
#include <QDebug>
#include <QQmlComponent>

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
    engine.globalObject().setProperty("advancedCalculator",
        engine.newQObject(new AdvancedCalculator));

    return app.exec();
}
