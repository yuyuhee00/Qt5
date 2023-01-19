#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/state.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/transition-rotate.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/state-when.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/transition.qml")));

    return app.exec();
}
