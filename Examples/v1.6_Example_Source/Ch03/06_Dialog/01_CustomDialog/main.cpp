#include <QApplication>
#include <QDebug>
#include "dialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Dialog dlg;

    int retVal = dlg.exec();
    if(retVal == QDialog::Accepted)
    {
        qDebug() << Q_FUNC_INFO << "QDialog::Accepted";
    }
    else if(retVal == QDialog::Rejected)
    {
        qDebug() << Q_FUNC_INFO << "QDialog::Rejected";
    }


    return a.exec();
}
