#ifndef IDRAWABLE_H
#define IDRAWABLE_H
#include "idrawer.h"
class IDrawable {
public:
    virtual void Draw() const = 0;
    virtual ~IDrawable() = default;
};

#endif // IDRAWABLE_H