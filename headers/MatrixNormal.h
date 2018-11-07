//
// Created by trojan52 on 06.10.18.
//

#ifndef LAB1_2_MATRIXNORMAL_H
#define LAB1_2_MATRIXNORMAL_H

#include "AMatrix.h"
#include "VectorNormal.h"
class MatrixNormal: public AMatrix {
public:
    MatrixNormal(unsigned long rows, unsigned long cols, IDrawer* d) : AMatrix(rows, cols, new MatrixNormal(), d) {}
    void Draw() override;
protected:
    MatrixNormal() = default;
    IVector* createVector(unsigned long size) const override;

};


#endif //LAB1_2_MATRIXNORMAL_H
