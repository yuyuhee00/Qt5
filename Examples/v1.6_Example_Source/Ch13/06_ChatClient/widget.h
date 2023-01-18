#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtNetwork/QTcpSocket>
#include "loginwidget.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    LoginWidget *loginWidget;

    QTcpSocket *socket;
    QString    ipAddr;
    QString    userName;

private slots:
    void loginInfo(QString addr, QString name);
    void sayButton_clicked();
    void connected();
    void readyRead();
};

#endif // WIDGET_H
