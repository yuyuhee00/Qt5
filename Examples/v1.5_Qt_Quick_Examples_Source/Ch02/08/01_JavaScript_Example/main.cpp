#include <QApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
//    engine.load(QUrl(QStringLiteral("qrc:/property_binding.qml")));
//    engine.load(QUrl(QStringLiteral("qrc:/function_binding.qml")));
//    engine.load(QUrl(QStringLiteral("qrc:/signal_handler.qml")));
    engine.load(QUrl(QStringLiteral("qrc:/qml_type.qml")));

//    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
