#include <QtWidgets>
#include "mainwindow.h"
#include <qtwebenginewidgetsglobal.h>

int main(int argc, char * argv[])
{
    QCoreApplication::setOrganizationName("QtExamples");
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);

    QUrl url = QUrl("http://www.qt-dev.com");

    MainWindow *browser = new MainWindow(url);
    browser->resize(1024, 768);
    browser->show();
    return app.exec();
}
