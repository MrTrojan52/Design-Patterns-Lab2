//
// Created by trojan52 on 06.10.18.
//

#ifndef LAB1_2_IMATRIX_H
#define LAB1_2_IMATRIX_H
#include "idrawable.h"

class IMatrix:public IDrawable {
public:
    virtual unsigned long getRows() const = 0;
    virtual unsigned long getCols() const = 0;
    virtual int get(int, int) const = 0;
    virtual void set(int, int, int) = 0;
    virtual ~IMatrix() = default;
};
#endif //LAB1_2_IMATRIX_H
