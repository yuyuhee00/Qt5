#include <QApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/effect1.qml"))); // Blend Effect
    //engine.load(QUrl(QStringLiteral("qrc:/effect2.qml"))); // BrightnessContrast Effect
    //engine.load(QUrl(QStringLiteral("qrc:/effect3.qml"))); // ColorOverlay Effect
    //engine.load(QUrl(QStringLiteral("qrc:/effect4.qml"))); // Colorize Effect
    //engine.load(QUrl(QStringLiteral("qrc:/effect5.qml"))); // Desaturate Effect
    //engine.load(QUrl(QStringLiteral("qrc:/effect6.qml"))); // GammaAdjust Effect
    //engine.load(QUrl(QStringLiteral("qrc:/effect7.qml"))); // HueSaturation Effect
    //engine.load(QUrl(QStringLiteral("qrc:/effect8.qml"))); // LevelAdjust Effect
    //engine.load(QUrl(QStringLiteral("qrc:/effect_Gradient.qml"))); // Gradient Effect
    //engine.load(QUrl(QStringLiteral("qrc:/effect9.qml"))); // Displace Effect
    //engine.load(QUrl(QStringLiteral("qrc:/effect10.qml"))); // DropShadow Effect
    //engine.load(QUrl(QStringLiteral("qrc:/effect11.qml"))); // FastBlur Effect
    //engine.load(QUrl(QStringLiteral("qrc:/effect12.qml"))); // GaussianBlur Effect
    //engine.load(QUrl(QStringLiteral("qrc:/effect13.qml"))); // DirectionBlur Effect
    //engine.load(QUrl(QStringLiteral("qrc:/effect14.qml"))); // RadialBlur Effect
    //engine.load(QUrl(QStringLiteral("qrc:/effect15.qml"))); // Glow Effect
    //engine.load(QUrl(QStringLiteral("qrc:/effect16.qml"))); // RectangularGlow Effect

    return app.exec();
}


