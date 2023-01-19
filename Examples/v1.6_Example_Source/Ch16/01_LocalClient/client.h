#ifndef CLIENT_H
#define CLIENT_H

#include <QDialog>
#include <QLocalSocket>
#include <qlocalsocket.h>

QT_BEGIN_NAMESPACE
class QDialogButtonBox;
class QLabel;
class QLineEdit;
class QPushButton;
class QLocalSocket;
QT_END_NAMESPACE

class Client : public QDialog
{
    Q_OBJECT

public:
    Client(QWidget *parent = 0);

private slots:
    void requestNewMsg();
    void readData();
    void sockError(QLocalSocket::LocalSocketError socketError);

private:
    QLabel *hostLabel;
    QLineEdit *hostLineEdit;
    QLabel *statusLabel;
    QPushButton *reqButton;
    QPushButton *quitButton;

    QLocalSocket *socket;
    quint16 blockSize;
};

#endif
