#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/new_main.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/checked_main.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/alias.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/myqt.qml")));

    return app.exec();
}
