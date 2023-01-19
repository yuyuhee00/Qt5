#ifndef WIDGET_H
#define WIDGET_H

#include <QCommandLinkButton>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QCommandLinkButton *cmmBtn;

private slots:
    void clickFunc();

};

#endif // WIDGET_H
