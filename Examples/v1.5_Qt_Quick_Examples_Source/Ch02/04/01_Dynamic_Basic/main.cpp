#include <QApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/dynamic_main.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/dynamic_component.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/application.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/key_main.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/square.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/status.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/value_change.qml")));

    return app.exec();
}
