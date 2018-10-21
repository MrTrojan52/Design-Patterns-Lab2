#include "qpaintwidget.h"

QPaintWidget::QPaintWidget(QWidget * parent) : QWidget(parent)
{
}


void QPaintWidget::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event)
    QPainter p(this); // Создаём новый объект рисовальщика
    p.setPen(QPen(Qt::red,1,Qt::SolidLine)); // Настройки рисования
    p.drawLine(0,0,width(),height()); // Рисование линии
}
