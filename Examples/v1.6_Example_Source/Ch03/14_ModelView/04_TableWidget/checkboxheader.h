#ifndef CHECKBOXHEADER_H
#define CHECKBOXHEADER_H

#include <QHeaderView>
#include <QObject>
#include <QPainter>
#include <QMouseEvent>

class CheckBoxHeader : public QHeaderView
{
    Q_OBJECT

public:
    CheckBoxHeader(Qt::Orientation orientation,
                   QWidget* parent = nullptr);

    bool isChecked() const { return isChecked_; }
    void setIsChecked(bool val);

signals:
    void checkBoxClicked(bool state);

protected:
    void paintSection(QPainter* painter,
                      const QRect& rect,
                      int logicalIndex) const;

    void mousePressEvent(QMouseEvent* event);

private:
    bool isChecked_;

    void redrawCheckBox();
};
#endif // CHECKBOXHEADER_H
