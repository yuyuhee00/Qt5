#ifndef TRIANGLEITEM_H
#define TRIANGLEITEM_H

#include <QQuickItem>
#include <QSGGeometry>
#include <QSGFlatColorMaterial>

class TriangleItem : public QQuickItem
{
    Q_OBJECT

public:
    TriangleItem(QQuickItem *parent = nullptr);

protected:
    QSGNode *updatePaintNode(QSGNode *node, UpdatePaintNodeData *data);

private:
    QSGGeometry m_geometry;
    QSGFlatColorMaterial m_material;
};

#endif
