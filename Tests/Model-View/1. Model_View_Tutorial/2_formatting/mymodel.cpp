// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#include "mymodel.h"

#include <QFont>
#include <QBrush>
#include <QDebug>

MyModel::MyModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

int MyModel::rowCount(const QModelIndex & /*parent */) const
{
    return 2;
}

int MyModel::columnCount(const QModelIndex & /*parent */) const
{
    return 3;
}

// mymodel.cpp

/*
 *  enum Qt::ItemDataRole
 *  {
 *      // General purpose roles
 *      Qt::DisplayRole             // 0, The key data to be rendered in the form of text. (QString)
 *      Qt::DecorationRole          // 1, The data to be rendered as a decorationin the from of an icon. (QColor, QIcon, QPixmap)
 *      Qt::EditRole                // 2, The data in a form suitable for editing in an editor. (QString)
 *      Qt::TooltipRole             // 3, The data displayed in the item's tooltip. (QString)
 *      Qt::StatusTipRole           // 4, The data displayed in the status bar. (QString)
 *      Qt::WhatsThisRole           // 5, The data displayed for the item in "What's This?" mode. (QString)
 *      Qt::SizeHintRole            // 13, The size hint for the item that will be supplied to views. (QSize)
 *
 *      // Roles descripbing appearance and meta data
 *      Qt::FontRole                // 6, The font used for items rendered with the default delegate. (QFont)
 *      Qt::TextAlignmentRole       // 7, The alignment of the text for items rendered with the default delegate. (Qt::Alignment)
 *      Qt::BackgroundRole          // 8, The background brush used for items rendered with the default delegate. (QBrush)
 *      Qt::BackgroundColorRole     // 8, This role is obsolete. Use BackgroundRole instead.
 *      Qt::ForegroundRole          // 9, The foreground brush (text color, typically) used for items rendered with the default delegate. (QBrush)
 *      Qt::ForegroundColorRole     // 9, This role is obsolete. Use ForegroundRole instead.
 *      Qt::CheckStateRole          // 10, This role is used to obtain the checked state of an item. (Qt::CheckState)
 *      Qt::InitialSortOrderRole    // 14, This role is used to obtain the initial sort order of a header view section. (Qt::SortOrder)
 *                                          This role was introduced in Qt 4.8
 *
 *      // Accessibility roles
 *      Qt::AccessibleTextRole          // 11, The text to be used by accessibility extensions and plugins, such as screen readers. (QString)
 *      Qt::AccessibleDescriptionRole   // 12, A description of the item for accessibility purposes. (QString)
 *
 *      // User roles
 *      Qt::UserRole                // 0x0100, The fir role that can be used for application-specific purposes.
 * }
 *
 * enum Qt::ItemFlag
 * {
 *      Qt::NoItemflags             // 0, It does not have any properties set.
 *      Qt::ItemIsSelectable        // 1, It can be selected.
 *      Qt::ItemIsEditable          // 2, It can be edited.
 *      Qt::ItemIsDragEnabled       // 4, It can be dragged.
 *      Qt::ItemIsDropEnabled       // 8, It can be used as a drop target.
 *      Qt::IttemIsUserCheckable    // 16, It can be checked or unchecked by the user.
 *      Qt::ItemIsEnabled           // 32, The user can interact with the item.
 *      Qt::ItemIsAutoTristate      // 64, The item's state depends on the state of its children.
 *                                          This enables automatic management of thestate of parent items in QTreeWidget
 *                                          (checked if all children are checked, unchecked if all children are unchecked. or
 *                                          partially checked if only some children are checked).
 *      Qt::ItemIsTristate          // 64, This enum value is deprecated. Use Qt::ItemIsAutoTristate instead.
 *      Qt::ItemNeverHasChildren    // 128, The item never has child items. This is used for optimization purposes only.
 *      Qt::ItemIsUserTristate      // 256, The user cna cycle through tree separate states. This value was added in Qt 5.5
 * }
 *
 */

QVariant MyModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    int col = index.column();

    // generate a log message when this method gets called
    qDebug() << QString("row %1, col%2, role %3").arg(row).arg(col).arg(role);

    switch (role) {
    case Qt::DisplayRole:
        if (row == 0 && col == 1) return QString("<--left");
        if (row == 1 && col == 1) return QString("right-->");

        return QString("Row%1, Column%2")
                .arg(row + 1)
                .arg(col +1);
    case Qt::FontRole:
        if (row == 0 && col == 0) { // change font only for cell(0,0)
            QFont boldFont;
            boldFont.setBold(true);
            return boldFont;
        }
        break;
    case Qt::BackgroundRole:
        if (row == 1 && col == 2)  // change background only for cell(1,2)
            return QBrush(Qt::red);
        break;
    case Qt::TextAlignmentRole:
        if (row == 1 && col == 1) // change text alignment only for cell(1,1)
            return int(Qt::AlignRight | Qt::AlignVCenter);
        break;
    case Qt::CheckStateRole:
        if (row == 1 && col == 0) // add a checkbox to cell(1,0)
            return Qt::Checked;
        break;
    }
    return QVariant();
}

bool MyModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role == Qt::EditRole) {
        if (!QAbstractItemModel::checkIndex(index)) return false;

        int row = index.row();
        int col = index.column();

        // generate a log message when this method gets called
        qDebug() << QString("Set Data : row %1, col%2, value - %3").arg(row).arg(col).arg(value.toString());

        return true;
    }
    return false;
}

Qt::ItemFlags MyModel::flags(const QModelIndex &index) const
{
    return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
}
