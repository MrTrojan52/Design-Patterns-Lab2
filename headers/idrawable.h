#ifndef IDRAWABLE_H
#define IDRAWABLE_H
#include "headers/idrawer.h"
class IDrawable {
public:
    virtual void Draw() = 0;
    virtual void setDrawer(IDrawer*) = 0;
    virtual ~IDrawable() = default;
};

#endif // IDRAWABLE_H
