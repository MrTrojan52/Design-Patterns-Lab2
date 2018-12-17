//
// Created by trojan52 on 06.10.18.
//

#ifndef LAB1_2_MATRIXNORMAL_H
#define LAB1_2_MATRIXNORMAL_H

#include "AMatrix.h"
#include "Vector/include/VectorNormal.h"
#include "Factories/include/vectornormalfactory.h"
class MatrixNormal: public AMatrix {
public:
    MatrixNormal(unsigned long rows, unsigned long cols, IDrawer* d) : AMatrix(rows, cols, new VectorNormalFactory, d) {}
    void Draw() const override;
    void iterate(std::function<void (int,int,int)>) const override;    
};


#endif //LAB1_2_MATRIXNORMAL_H
