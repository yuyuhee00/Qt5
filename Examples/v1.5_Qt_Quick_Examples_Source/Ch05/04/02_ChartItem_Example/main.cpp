
#include <QGuiApplication>
#include <QQuickView>
#include "baritem.h"
#include "chartitem.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    qmlRegisterType<ChartItem>("Shapes", 1, 0, "Chart");
    qmlRegisterType<BarItem>("Shapes", 1, 0, "Bar");

    QQuickView view;
    view.setSource(QUrl("qrc:///chart.qml"));
    view.show();
    return app.exec();
}
