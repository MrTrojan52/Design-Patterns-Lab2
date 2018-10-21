//
// Created by trojan52 on 06.10.18.
//

#ifndef LAB1_2_AMATRIX_H
#define LAB1_2_AMATRIX_H

#include "IMatrix.h"
#include "IVector.h"
#include <vector>
#include "VectorNormal.h"
class AMatrix: public IMatrix {
public:
    AMatrix(long rows, long cols, AMatrix* matrix) {
        this->data.resize(rows);
        for(long i = 0; i < rows; ++i)
            this->data[i] = matrix->createVector(cols);
        delete matrix;

    }
    virtual ~AMatrix(){
        for(long i = 0; i < data.size(); ++i) {
            delete data[i];
        }
    }
    unsigned long getRows() const override ;
    unsigned long getCols() const override;
    int get(int row, int col) const override;
    void set(int row, int col, int val) override;
protected:
    AMatrix() = default;
    virtual IVector* createVector(long size) const = 0;

private:
    std::vector<IVector*> data;
};


#endif //LAB1_2_AMATRIX_H
