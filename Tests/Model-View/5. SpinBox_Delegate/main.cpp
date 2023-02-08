#include "SpinBoxDelegate.h"

#include <QApplication>
#include <QStandardItemModel>
#include <QTableView>
#include <QModelIndex>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QStandardItemModel model(4, 10);
    QTableView tableView;
    tableView.setModel(&model);

    SpinBoxDelegate delegate;
    tableView.setItemDelegate(&delegate);

    for(int row = 0; row < 4; ++row) {
        for(int col = 0; col < 10; ++col) {
            QModelIndex index = model.index(row, col, QModelIndex());
            model.setData(index, QVariant((row+1)*(col+1)));
        }
    }

    tableView.setWindowTitle(QObject::tr("Spin Box Delegate"));
    tableView.show();

    return a.exec();
}
