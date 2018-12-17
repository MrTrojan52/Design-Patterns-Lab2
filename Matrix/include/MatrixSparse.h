//
// Created by trojan52 on 10.10.18.
//

#ifndef LAB1_2_MATRIXSPARSE_H
#define LAB1_2_MATRIXSPARSE_H

#include "AMatrix.h"
#include "Vector/include/VectorSparse.h"
#include "Factories/include/vectorsparsefactory.h"
class MatrixSparse: public AMatrix {
public:
    MatrixSparse(unsigned long rows, unsigned long cols, IDrawer *d) : AMatrix(rows, cols, new VectorSparseFactory, d) {}
    void iterate(std::function<void (int,int,int)>) const override;
    void Draw() const override;
};


#endif //LAB1_2_MATRIXSPARSE_H
