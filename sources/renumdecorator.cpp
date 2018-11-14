#include "headers/renumdecorator.h"

unsigned long RenumDecorator::getRows() const {
    return this->_matrix->getRows();
}

unsigned long RenumDecorator::getCols() const {
    return this->_matrix->getCols();
}

int RenumDecorator::get(unsigned long row, unsigned long col) const {
    std::tie(row, col) = this->getSwapped(row, col);

    return this->_matrix->get(row, col);
}

void RenumDecorator::set(unsigned long row, unsigned long col, int val) {
    std::tie(row, col) = this->getSwapped(row, col);

    this->_matrix->set(row, col, val);
}

std::shared_ptr<AMatrix> RenumDecorator::getComponent() {
    return this->_matrix->getComponent();
}

void RenumDecorator::swapCols(int c1, int c2) {
    if(c1 >= 0 && c1 < getCols() && c2 >= 0 && c2 < getCols() && c1 != c2 && this->_matrix->getCols() != 1) {
        this->swapCol1 = c1;
        this->swapCol2 = c2;
    }
}

void RenumDecorator::swapRows(int r1, int r2) {
    if(r1 >= 0 && r1 < getRows() && r2 >= 0 && r2 < getRows() && r1 != r2 && this->_matrix->getRows() != 1) {
        this->swapRow1 = r1;
        this->swapRow2 = r2;
    }
}

std::tuple<int, int> RenumDecorator::getSwapped(int row, int col) const {
    if(row == this->swapRow1) row = this->swapRow2;
    else if(row == this->swapRow2) row = this->swapRow1;

    if(col == this->swapCol1) col = this->swapCol2;
    else if(col == this->swapCol2) col = this->swapCol1;
    return std::make_tuple(row, col);
}

void RenumDecorator::Draw() const{
    unsigned long rows = this->getRows();
    unsigned long cols = this->getCols();
    DrawBorder(rows, cols);
    this->_matrix->iterate([this](int r, int c, int val)-> void{
        int row, col;
        std::tie(row,col) = this->getSwapped(r, c);
        DrawItem(row, col, val);
    });
}

void RenumDecorator::setDrawer(IDrawer* d) {
    AMatrix::setDrawer(d);
    this->_matrix->setDrawer(d);
}

void RenumDecorator::iterate(std::function<void (int,int,int)> func) const {
    this->_matrix->iterate([this, func](int r, int c, int val)->void {
        int row, col;
        std::tie(row,col) = this->getSwapped(r, c);
        func(row,col,val);
    });
}
