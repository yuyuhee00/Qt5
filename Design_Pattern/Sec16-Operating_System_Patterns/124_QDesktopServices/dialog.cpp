#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_btnWeb_clicked()
{
    QDesktopServices::openUrl(QUrl("http://www.voidrealms.com"));
}

void Dialog::on_btnFile_clicked()
{
    QString file;
    file.append("file://");
    file.append("/home/rootshell/Pictures/meaning.jpg");
    QDesktopServices::openUrl(QUrl(file));
}

void Dialog::on_btnCustom_clicked()
{
    // Help
    QDesktopServices::openUrl(QUrl("help://HelpME"));
}

void Dialog::showHelp(const QUrl &url)
{
    // From on_btnCustom_clicked;
    qInfo() << "Sender : " << sender();
    QMessageBox::information(this, "Help", url.url());
}
