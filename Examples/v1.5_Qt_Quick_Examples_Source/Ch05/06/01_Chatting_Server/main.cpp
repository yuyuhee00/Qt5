#include <QApplication>
#include <QQuickView>
#include <QUrl>
#include <qqml.h>
#include "tcpconnection.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qmlRegisterType<TcpConnection>("TCP", 1, 0, "TcpConnection");

    QQuickView view;

    view.setSource(QUrl("qrc:///Server.qml"));
    view.show();

    return app.exec();
}
