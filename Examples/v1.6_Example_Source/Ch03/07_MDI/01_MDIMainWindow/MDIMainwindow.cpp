#include "MDIMainwindow.h"
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QPushButton>
#include <QDebug>

MDIMainWindow::MDIMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(QString::fromUtf8("My MDI"));

    mdiAria = new QMdiArea();
    mdiAria->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    // MdiSubWindow 생성
    QMdiSubWindow* subWindow1 = new QMdiSubWindow();
    subWindow1->resize(300, 200);

    QPushButton *btn = new QPushButton(QString("Button"));
    subWindow1->setWidget(btn);


    QMdiSubWindow* subWindow2 = new QMdiSubWindow();
    subWindow2->resize(300, 200);

    // MDIMainWindows에 서브 윈도우 추가
    mdiAria->addSubWindow(subWindow1);
    //mdiAria->addSubWindow(subWindow2);

    setCentralWidget(mdiAria);
}

void MDIMainWindow::addSubWindow()
{
    QMdiSubWindow* subWindow = new QMdiSubWindow();
    subWindow->resize(300, 200);

    mdiAria->addSubWindow(subWindow);
    subWindow->show();

    qInfo() << "Adding Sub Window";
}
