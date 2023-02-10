#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = 0);

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // MYWIDGET_H
