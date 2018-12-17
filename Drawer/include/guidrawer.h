#ifndef GUIDRAWER_H
#define GUIDRAWER_H
#include "adrawer.h"
#include <QPainter>
class GuiDrawer : public ADrawer {
public:
    GuiDrawer() { _RecW = 80; _RecH = 25;}
    void DrawBorder(unsigned long rows, unsigned long cols) override;
    void DrawItem(unsigned long row, unsigned long col, int val) const override;
    void setPainter(QPainter*);
private:
    QPainter* _painter;
    int _RecW;
    int _RecH;
};

#endif // GUIDRAWER_H
