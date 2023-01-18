#ifndef WIDGET_H
#define WIDGET_H

#include <QDate>
#include <QDateEdit>
#include <QLabel>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QDateEdit *dateEdit[4];
    QLabel *lbl[6];
};

#endif // WIDGET_H
