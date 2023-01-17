#include "dialog.h"
#include "ui_dialog.h"

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
    QDesktopServices::openUrl(QUrl("help://HelpME"));
}

void Dialog::showHelp(const QUrl &url)
{
    QMessageBox::information(this,"Help", url.url());
}
