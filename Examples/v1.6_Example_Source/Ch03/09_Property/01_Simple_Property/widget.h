#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "person.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void buttonPressed();
    void nameChanged(const QString &n);

private:
    Ui::Widget *ui;

    Person *goodman;
};

#endif // WIDGET_H
