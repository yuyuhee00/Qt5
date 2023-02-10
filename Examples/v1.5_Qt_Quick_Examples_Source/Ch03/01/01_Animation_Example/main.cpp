#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/numberanimation.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/propertyanimation.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/rotationanimation.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/ani_event_complex.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/behaivor.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/smoothedanimation.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/springanimation.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/sequentialanimation.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/parallelanimation.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/sequential-animation-nested.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/easingcurve.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/pauseanimation.qml")));

    return app.exec();
}
