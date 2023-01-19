#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QUdpSocket>
#include <QTimer>

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

    QUdpSocket  *udpSocket;
    QTimer      *timer;
    int          msgNumber;

private slots:
    void startButton();
    void broadcastSend();

};

#endif // WIDGET_H
