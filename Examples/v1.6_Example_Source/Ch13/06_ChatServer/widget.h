#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "chatserver.h"

namespace Ui {
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    ChatServer *server;

private slots:
    void slot_clients(int users);
    void slot_message(QString msg);
};

#endif // WIDGET_H
