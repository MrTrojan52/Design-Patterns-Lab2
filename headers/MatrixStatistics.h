//
// Created by trojan52 on 10.10.18.
//

#ifndef LAB1_2_MATRIXSTATISTICS_H
#define LAB1_2_MATRIXSTATISTICS_H

#include "AMatrix.h"

class MatrixStatistics {
public:
    explicit MatrixStatistics(IMatrix* const matrix);

public:
    long notZeroCount() const;
    long sum() const;
    int maxValue() const;
    double average() const;

private:
    IMatrix* _matrix;
};


#endif //LAB1_2_MATRIXSTATISTICS_H
