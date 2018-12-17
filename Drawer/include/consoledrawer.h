#ifndef CONSOLEDRAWER_H
#define CONSOLEDRAWER_H

#include "adrawer.h"
class ConsoleDrawer: public ADrawer
{
public:
    ConsoleDrawer(int width = 6) { _cell_width = width > 0 ? width : 6;}
    void DrawBorder(unsigned long rows, unsigned long cols) override;
    void DrawItem(unsigned long row, unsigned long col, int val) const override;
private:
    int _cell_width;
};

#endif // CONSOLEDRAWER_H
