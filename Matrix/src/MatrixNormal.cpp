//
// Created by trojan52 on 06.10.18.
//

#include "Matrix/include/MatrixNormal.h"

void MatrixNormal::Draw() const {
    unsigned long rows = this->getRows();
    unsigned long cols = this->getCols();
    DrawBorder(rows, cols);
    this->iterate([this](int r, int c, int val)->void {
        this->DrawItem(r, c ,val);
    });
}

void MatrixNormal::iterate(std::function<void (int,int,int)> func) const {
    unsigned long rows = this->getRows();
    unsigned long cols = this->getCols();
    for(unsigned long r = 0; r < rows; ++r) {
        for(unsigned long c = 0; c < cols; ++c) {
            func(r, c, this->get(r, c));
        }
    }
}
