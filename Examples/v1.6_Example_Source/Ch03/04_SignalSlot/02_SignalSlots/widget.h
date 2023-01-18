#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "counter.h"

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

    Counter *cnt1;
    Counter *cnt2;

private slots:
    void slotPbtButtonClick();

};

#endif // WIDGET_H
