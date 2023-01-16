#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDebug>
#include <QStateMachine>
#include <QState>
#include <QHistoryState>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    void createStates();

private slots:
    void on_btnNext_clicked();
    void on_btnBack_clicked();
    void on_lineEdit_textEdited(const QString &arg1);
    void on_btnBookmark_clicked();
    void on_btnJump_clicked();

    void stateEntered();
    void stateExited();
    void stateFinished();

private:
    Ui::Dialog *ui;
    QStateMachine m_statemachine;
    QState m_root;
    QState* m_current;
    QHistoryState *m_history;
};
#endif // DIALOG_H
