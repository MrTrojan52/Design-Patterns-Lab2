#ifndef IDRAWER_H
#define IDRAWER_H

class IDrawer {
public:
    virtual void DrawBorder(unsigned long rows, unsigned long cols) = 0;
    virtual void DrawItem(unsigned long row, unsigned long col, int val) const = 0;
    virtual ~IDrawer() = default;
};

#endif // IDRAWER_H
