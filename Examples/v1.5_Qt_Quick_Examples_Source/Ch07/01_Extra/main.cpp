#include <QApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/delaybutton.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/dial.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/piemenu.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/togglebutton.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/tumbler.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/tumbler_model.qml")));

    return app.exec();
}
