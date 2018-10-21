#ifndef QPAINTWIDGET_H
#define QPAINTWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>

class QPaintWidget: public QWidget
{
    Q_OBJECT
public:
    QPaintWidget(QWidget * parent = nullptr);
protected:
    void paintEvent(QPaintEvent *);
signals:


public slots:
};

#endif // QPAINTWIDGET_H
