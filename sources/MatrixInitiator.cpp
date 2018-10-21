//
// Created by trojan52 on 10.10.18.
//

#include "headers/MatrixInitiator.h"
#include <ctime>
#include <numeric>
#include <vector>
void MatrixInitiator::fillMatrix(AMatrix * const matrix, long nonZeroCount, long maxValue) {
    srand(time(nullptr));
    unsigned long rows = matrix->getRows();
    unsigned long cols = matrix->getCols();
    long count = 0;
    std::vector<int> indices(rows * cols);
    std::iota(indices.begin(), indices.end(), 0);
    while (count != nonZeroCount && count < rows*cols)
    {
        unsigned long pos = rand() % indices.size();
        matrix->set(indices[pos] / cols, indices[pos] % cols, rand() % maxValue + 1);
        indices.erase(indices.begin() + pos);
        ++count;
    }
}
