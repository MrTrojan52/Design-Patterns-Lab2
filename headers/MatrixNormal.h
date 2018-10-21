//
// Created by trojan52 on 06.10.18.
//

#ifndef LAB1_2_MATRIXNORMAL_H
#define LAB1_2_MATRIXNORMAL_H

#include "AMatrix.h"
#include "VectorNormal.h"
class MatrixNormal: public AMatrix {
public:
    MatrixNormal(int rows, int cols, IDrawer* d) : AMatrix(rows, cols, new MatrixNormal(), d) {}

protected:
    MatrixNormal() = default;
    IVector* createVector(long size) const override;

};


#endif //LAB1_2_MATRIXNORMAL_H
