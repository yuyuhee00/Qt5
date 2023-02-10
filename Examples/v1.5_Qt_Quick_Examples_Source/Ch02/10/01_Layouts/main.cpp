#include <QApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/rowlayout.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/columnlayout.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/gridlayout.qml")));

    return app.exec();
}
