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

int AMatrix::get(unsigned long row, unsigned long col) const {
    return this->data[row]->get(col);
}

void AMatrix::set(unsigned long row, unsigned long col, int val) {
    this->data[row]->set(col, val);
}

void AMatrix::setDrawer(IDrawer *d) {
    this->drawer = d;
}

void AMatrix::DrawBorder(unsigned long rows, unsigned long cols) const {
    this->drawer->DrawBorder(rows, cols);
}

void AMatrix::DrawItem(unsigned long row, unsigned long col, int val) const {
    this->drawer->DrawItem(row, col, val);
}
