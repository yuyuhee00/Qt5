#ifndef WIDGET_H
#define WIDGET_H

#include <QComboBox>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QComboBox *combo;

private slots:
    void valueChanged(int);
};

#endif // WIDGET_H
