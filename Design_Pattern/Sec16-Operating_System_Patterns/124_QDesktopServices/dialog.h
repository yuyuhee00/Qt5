#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDesktopServices>
#include <QUrl>
#include <QMessageBox>

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
    void on_btnWeb_clicked();
    void on_btnFile_clicked();
    void on_btnCustom_clicked();

public slots:
    void showHelp(const QUrl &url);

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
