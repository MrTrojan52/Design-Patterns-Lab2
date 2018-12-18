#include "Drawer/include/guidrawer.h"


void GuiDrawer::DrawBorder(unsigned long rows, unsigned long cols) {
    _RecW = _painter->window().width() / cols;
    _RecH = _painter->window().height() / rows;
    if(_needBorder) {
        _painter->setPen(QColor(Qt::black));
        for(unsigned long r = 0; r < rows; ++r) {
            for(unsigned long c = 0; c < cols; ++c) {
                _painter->drawRect(_RecW * c, _RecH * r,_RecW, _RecH);
            }
        }
    }

}
void GuiDrawer::DrawItem(unsigned long row, unsigned long col, int val) const {
     _painter->drawText((_RecW * col + _RecW * (col + 1)) / 2, (_RecH * row + _RecH * (row + 1)) / 2, QString::number(val));
}


void GuiDrawer::setPainter(QPainter* p) {
    _painter = p;
}
