#pragma once

#include <QAbstractTableModel>
#include <QImage>

class ImageModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit ImageModel(QObject *parent = nullptr);

    void setImage(const QImage &newModelImage);

private:
    QImage modelImage;

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
};

