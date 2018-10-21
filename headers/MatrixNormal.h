//
// Created by trojan52 on 06.10.18.
//

#ifndef LAB1_2_MATRIXNORMAL_H
#define LAB1_2_MATRIXNORMAL_H

#include "AMatrix.h"
#include "VectorNormal.h"
class MatrixNormal: public AMatrix {
public:
    MatrixNormal(int rows, int cols) : AMatrix(rows, cols, new MatrixNormal()) {}

protected:
    MatrixNormal() = default;
    IVector* createVector(long size) const override {
        return new VectorNormal(size);
    }

};


#endif //LAB1_2_MATRIXNORMAL_H
