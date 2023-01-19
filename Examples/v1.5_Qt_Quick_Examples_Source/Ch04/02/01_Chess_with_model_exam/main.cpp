#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/chess-board1.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/chess-board2.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/chess-board3.qml")));

    return app.exec();
}
