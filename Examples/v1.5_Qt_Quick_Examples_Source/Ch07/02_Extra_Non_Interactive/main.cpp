#include <QApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/circulargauge.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/gauge.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/gauge2.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/statusindicator.qml")));

    return app.exec();
}
