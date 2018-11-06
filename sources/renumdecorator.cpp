#include "headers/renumdecorator.h"


unsigned long RenumDecorator::getRows() const {
    return this->_matrix->getRows();
}

unsigned long RenumDecorator::getCols() const {
    return this->_matrix->getCols();
}

int RenumDecorator::get(unsigned long row, unsigned long col) const {
    row = row == swapRow1 ? swapRow2 : row;
    col = col == swapCol1 ? swapCol2 : col;
    return this->_matrix->get(row, col);
}

void RenumDecorator::set(unsigned long row, unsigned long col, int val) {
    row = row == swapRow1 ? swapRow2 : row;
    col = col == swapCol1 ? swapCol2 : col;
    this->_matrix->set(row, col, val);
}

IMatrix* RenumDecorator::getComponent() {
    return this->_matrix->getComponent();
}


void RenumDecorator::swapCols(int c1, int c2) {
    this->swapCol1 = c1;
    this->swapCol2 = c2;
}

void RenumDecorator::swapRows(int r1, int r2) {
    this->swapRow1 = r1;
    this->swapRow2 = r2;
}

void RenumDecorator::Draw() const {
    //TODO: Код отрисовки
}
