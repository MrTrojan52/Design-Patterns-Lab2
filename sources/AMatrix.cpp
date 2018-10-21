//
// Created by trojan52 on 06.10.18.
//

#include "headers/AMatrix.h"


unsigned long AMatrix::getRows() const {
    return this->data.size();
}


unsigned long AMatrix::getCols() const {
    return this->data[0]->getSize();
}

int AMatrix::get(int row, int col) const {
    return this->data[row]->get(col);
}

void AMatrix::set(int row, int col, int val) {
    this->data[row]->set(col, val);
}

