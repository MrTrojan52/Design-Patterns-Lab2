//
// Created by trojan52 on 10.10.18.
//

#ifndef LAB1_2_MATRIXSPARSE_H
#define LAB1_2_MATRIXSPARSE_H

#include "AMatrix.h"
#include "VectorSparse.h"

class MatrixSparse: public AMatrix {
public:
    MatrixSparse(unsigned long rows, unsigned long cols, IDrawer *d) : AMatrix(rows, cols, new MatrixSparse(), d) {}
    void Draw() override;
protected:
    MatrixSparse() = default;
    IVector* createVector(unsigned long size) const override;
};


#endif //LAB1_2_MATRIXSPARSE_H
