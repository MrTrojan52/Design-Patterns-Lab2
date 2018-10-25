#include "qpaintwidget.h"
#include <iostream>
QPaintWidget::QPaintWidget(QWidget * parent) : QWidget(parent)
{
}


void QPaintWidget::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event)
    //QPainter* p = new QPainter(this);

//    p->setPen(QPen(Qt::red,1,Qt::SolidLine));
//    p->drawLine(0,0,width(),height());
 //   delete p;
}
