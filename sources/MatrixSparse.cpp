//
// Created by trojan52 on 10.10.18.
//

#include "headers/MatrixSparse.h"

IVector* MatrixSparse::createVector(unsigned long size) const {
    return new VectorSparse(size);
}

void MatrixSparse::Draw() {
    unsigned long rows = this->getRows();
    unsigned long cols = this->getCols();
    DrawBorder(rows, cols);
    for(unsigned long r = 0; r < rows; ++r) {
        for(unsigned long c = 0; c < cols; ++c) {
            int item = this->get(r, c);
            if(item) {
                DrawItem(r, c, item);
            }
        }
    }
}
