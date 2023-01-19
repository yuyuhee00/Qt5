#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    engine.load(QUrl(QStringLiteral("qrc:/rectangle.qml"))); // Rectangle 예제
    //engine.load(QUrl(QStringLiteral("qrc:/image.qml"))); // Image 예제
    //engine.load(QUrl(QStringLiteral("qrc:/animatedimage.qml"))); // AnimatedImage 예제
    //engine.load(QUrl(QStringLiteral("qrc:/anchors.qml"))); // anchors 예제
    //engine.load(QUrl(QStringLiteral("qrc:/text_image_anchors.qml"))); // anchors 를 이용한 여러개의 Type 배치 예제
    //engine.load(QUrl(QStringLiteral("qrc:/gradient.qml"))); // gradient
    //engine.load(QUrl(QStringLiteral("qrc:/systempalette.qml"))); // SystemPalette
    //engine.load(QUrl(QStringLiteral("qrc:/screen.qml"))); // screen
    //engine.load(QUrl(QStringLiteral("qrc:/fontloader.qml"))); // fontloader
    //engine.load(QUrl(QStringLiteral("qrc:/repeater.qml"))); // Repeater
    //engine.load(QUrl(QStringLiteral("qrc:/image.qml"))); // Image
    //engine.load(QUrl(QStringLiteral("qrc:/transformation.qml"))); // Transformation
    //engine.load(QUrl(QStringLiteral("qrc:/simple_accessible.qml"))); // Accessible

    return app.exec();
}

