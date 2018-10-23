#ifndef CONSOLEDRAWER_H
#define CONSOLEDRAWER_H

#include "idrawer.h"
class ConsoleDrawer: public IDrawer
{
public:
    ConsoleDrawer() = default;
    void DrawBorder(unsigned long rows, unsigned long cols) const override;
    void DrawItem(unsigned long row, unsigned long col, int val) const override;
};

#endif // CONSOLEDRAWER_H
