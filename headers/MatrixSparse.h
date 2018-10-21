//
// Created by trojan52 on 10.10.18.
//

#ifndef LAB1_2_MATRIXSPARSE_H
#define LAB1_2_MATRIXSPARSE_H

#include "AMatrix.h"
#include "VectorSparse.h"

class MatrixSparse: public AMatrix {
public:
    MatrixSparse(int rows, int cols) : AMatrix(rows, cols, new MatrixSparse()) {}

protected:
    MatrixSparse() = default;
    IVector* createVector(long size) const override {
        return new VectorSparse(size);
    }
};


#endif //LAB1_2_MATRIXSPARSE_H
