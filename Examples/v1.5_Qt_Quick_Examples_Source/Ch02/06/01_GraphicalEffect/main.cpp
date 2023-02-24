#include <QApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
//    engine.load(QUrl(QStringLiteral("qrc:/blend.qml"))); // Blend Effect
//    engine.load(QUrl(QStringLiteral("qrc:/brightness_contrast.qml"))); // BrightnessContrast Effect
//    engine.load(QUrl(QStringLiteral("qrc:/color_overlay.qml"))); // ColorOverlay Effect
//    engine.load(QUrl(QStringLiteral("qrc:/colorize.qml"))); // Colorize Effect
//    engine.load(QUrl(QStringLiteral("qrc:/desaturate.qml"))); // Desaturate Effect
//    engine.load(QUrl(QStringLiteral("qrc:/gamma_adjust.qml"))); // GammaAdjust Effect
//    engine.load(QUrl(QStringLiteral("qrc:/hue_saturation.qml"))); // HueSaturation Effect
//    engine.load(QUrl(QStringLiteral("qrc:/level_adjust.qml"))); // LevelAdjust Effect
//    engine.load(QUrl(QStringLiteral("qrc:/effect_Gradient.qml"))); // Gradient Effect
//    engine.load(QUrl(QStringLiteral("qrc:/displace.qml"))); // Displace Effect
//    engine.load(QUrl(QStringLiteral("qrc:/drop_shadow.qml"))); // DropShadow Effect
//    engine.load(QUrl(QStringLiteral("qrc:/fast_blur.qml"))); // FastBlur Effect
//    engine.load(QUrl(QStringLiteral("qrc:/gaussian_blur.qml"))); // GaussianBlur Effect
//    engine.load(QUrl(QStringLiteral("qrc:/direction_blur.qml"))); // DirectionBlur Effect
//    engine.load(QUrl(QStringLiteral("qrc:/radial_blur.qml"))); // RadialBlur Effect
//    engine.load(QUrl(QStringLiteral("qrc:/glow.qml"))); // Glow Effect
    engine.load(QUrl(QStringLiteral("qrc:/rectangular_glow.qml"))); // RectangularGlow Effect

    return app.exec();
}


