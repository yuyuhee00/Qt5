#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTabBar>

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void currentTab(int index);
};

#endif // WIDGET_H
