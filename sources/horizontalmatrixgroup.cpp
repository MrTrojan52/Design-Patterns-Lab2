#include "headers/horizontalmatrixgroup.h"
#include <algorithm>
#include <numeric>
unsigned long HorizontalMatrixGroup::getRows() const {
    return (*(std::max_element(_mVec.begin(), _mVec.end(), [](const std::shared_ptr<AMatrix> m1, const std::shared_ptr<AMatrix> m2)->bool {return m1->getRows() < m2->getRows();})))->getRows();
}

unsigned long HorizontalMatrixGroup::getCols() const {
    return std::accumulate(_mVec.begin(),_mVec.end(), 0, [](int& m1, const std::shared_ptr<AMatrix> m2)->int {return m1 + m2->getCols();});
}

int HorizontalMatrixGroup::get(unsigned long row, unsigned long col) const {
    int offset = 0;
    for(int i = 0; i < _mVec.size(); ++i)
    {
        if(col < offset + _mVec[i]->getCols()) {
            if(row < _mVec[i]->getRows()) {
                return _mVec[i]->get(row, col - offset);
            } else {
                return 0;
            }
        }
        offset += _mVec[i]->getCols();
    }
    return 0;
}
void HorizontalMatrixGroup::set(unsigned long row, unsigned long col, int val) {
    int offset = 0;
    for(int i = 0; i < _mVec.size(); ++i)
    {
        if(col < offset + _mVec[i]->getCols()) {
            if(row < _mVec[i]->getRows()) {
               _mVec[i]->set(row, col - offset, val);
               return;

            }
        }
        offset += _mVec[i]->getCols();
    }
}

void HorizontalMatrixGroup::Draw() const {
    DrawBorder(this->getRows(), this->getCols());
    int offset = 0;
    for(auto& x : _mVec){
        x->iterate([this, offset](int row, int col, int val)->void {
           DrawItem(row, col + offset, val);
        });
        offset += x->getCols();
    }
}
void HorizontalMatrixGroup::iterate(std::function<void (int,int,int)> func) const {
    int offset = 0;
    for(auto x : _mVec) {
        x->iterate([offset, func](int row, int col, int val)->void {
           func(row, col + offset, val);
        });
    offset += x->getCols();
    }
}

void HorizontalMatrixGroup::Add(std::shared_ptr<AMatrix> matrix) {
    _mVec.push_back(matrix);
}

void HorizontalMatrixGroup::setDrawer(IDrawer* d) {
    AMatrix::setDrawer(d);
    for(auto& x : _mVec)
        x->setDrawer(d);
}
