#ifndef WIDGET_H
#define WIDGET_H

#include <QPushButton>
#include <QPropertyAnimation>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    QPropertyAnimation* m_animation;

public slots:
    void btnClicked();


    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);
};

#endif // WIDGET_H
