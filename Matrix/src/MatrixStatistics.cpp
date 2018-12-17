//
// Created by trojan52 on 10.10.18.
//

#include "Matrix/include/MatrixStatistics.h"
#include <limits>
MatrixStatistics::MatrixStatistics(IMatrix *const matrix):_matrix(matrix) { }

long MatrixStatistics::sum() const {
    long sum = 0;
    unsigned long rows = this->_matrix->getRows();
    unsigned long cols = this->_matrix->getCols();
    for(unsigned long i = 0; i < rows; ++i) {
        for (unsigned long j = 0; j < cols; ++j) {
            sum += this->_matrix->get(i, j);
        }
    }
    return sum;
}


long MatrixStatistics::notZeroCount() const {
    long count = 0;
    unsigned long  rows = this->_matrix->getRows();
    unsigned long  cols = this->_matrix->getCols();
    for(unsigned long i = 0; i < rows; ++i) {
        for (unsigned long j = 0; j < cols; ++j) {
            if(this->_matrix->get(i, j)) ++count;
        }
    }
    return count;
}

int MatrixStatistics::maxValue() const {
    int max = std::numeric_limits<int>::min();
    unsigned long rows = this->_matrix->getRows();
    unsigned long cols = this->_matrix->getCols();
    for(unsigned long i = 0; i < rows; ++i) {
        for (unsigned long j = 0; j < cols; ++j) {
            int item = this->_matrix->get(i, j);
            max = item > max ? item : max;
        }
    }
    return max;
}

double MatrixStatistics::average() const {
    return static_cast<double>(this->sum()) / (this->_matrix->getRows() * this->_matrix->getCols());
}
