#ifndef WIDGET_H
#define WIDGET_H

#include <QTime>
#include <QTimeEdit>
#include <QLabel>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
};

#endif // WIDGET_H
