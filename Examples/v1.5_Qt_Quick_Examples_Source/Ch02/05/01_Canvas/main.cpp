#include <QApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/canvas_basic.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/canvas_rect.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/canvas_gradients.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/canvas_mousedrawing.qml")));

    return app.exec();
}
