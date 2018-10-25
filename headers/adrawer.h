#ifndef ADRAWER_H
#define ADRAWER_H
#include "idrawer.h"
class ADrawer : public IDrawer {
public:
    void needBorder(bool needBorder) {
        this->_needBorder = needBorder;
    }
protected:
    bool _needBorder = true;
};


#endif // ADRAWER_H
