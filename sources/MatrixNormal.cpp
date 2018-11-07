//
// Created by trojan52 on 06.10.18.
//

#include "headers/MatrixNormal.h"


IVector* MatrixNormal::createVector(unsigned long size) const {
    return new VectorNormal(size);
}

void MatrixNormal::Draw() {
    unsigned long rows = this->getRows();
    unsigned long cols = this->getCols();
    DrawBorder(rows, cols);
    for(unsigned long r = 0; r < rows; ++r) {
        for(unsigned long c = 0; c < cols; ++c) {
            DrawItem(r, c, this->get(r, c));
        }
    }
}
