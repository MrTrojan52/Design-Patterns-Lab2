//
// Created by trojan52 on 10.10.18.
//

#include "Matrix/include/MatrixSparse.h"

void MatrixSparse::Draw() const {
    unsigned long rows = this->getRows();
    unsigned long cols = this->getCols();
    DrawBorder(rows, cols);
    this->iterate([this](int r, int c, int val)->void{
        if(val)
            this->DrawItem(r, c, val);
    });

}

void MatrixSparse::iterate(std::function<void (int,int,int)> func) const {
    unsigned long rows = this->getRows();
    unsigned long cols = this->getCols();
    for(unsigned long r = 0; r < rows; ++r) {
        for(unsigned long c = 0; c < cols; ++c) {
            int val = this->get(r,c);
            if(val)
                func(r, c, val);
        }
    }
}
