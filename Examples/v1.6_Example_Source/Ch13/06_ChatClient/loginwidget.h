#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>

namespace Ui {
class LoginWidget;
}

class LoginWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWidget(QWidget *parent = nullptr);
    ~LoginWidget();

private:
    Ui::LoginWidget *ui;

private slots:
    void loginBtnClicked();

signals:
    void loginInfo(QString addr, QString name);
};

#endif // LOGINWIDGET_H
