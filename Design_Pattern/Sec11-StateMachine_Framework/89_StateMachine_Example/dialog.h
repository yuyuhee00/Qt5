#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDebug>
#include <QStateMachine>
#include <QState>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_clicked();
    void stateEntered();
    void stateExited();

private:
    Ui::Dialog *ui;

    //The state machine
    QStateMachine m_statemachine;

    //Some states we want to have
    QState m_state1;
    QState m_state2;
    QState m_state3;

};
#endif // DIALOG_H
