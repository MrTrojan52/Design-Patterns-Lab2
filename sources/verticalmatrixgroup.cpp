#include "headers/verticalmatrixgroup.h"

#include <algorithm>
#include <numeric>
unsigned long VerticalMatrixGroup::getCols() const {
    return (*(std::max_element(_mVec.begin(), _mVec.end(), [](const std::shared_ptr<AMatrix> m1, const std::shared_ptr<AMatrix> m2)->bool {return m1->getCols() < m2->getCols();})))->getCols();
}

unsigned long VerticalMatrixGroup::getRows() const {
    return std::accumulate(_mVec.begin(),_mVec.end(), 0, [](int& m1, const std::shared_ptr<AMatrix> m2)->int {return m1 + m2->getRows();});
}

int VerticalMatrixGroup::get(unsigned long row, unsigned long col) const {
    int offset = 0;
    for(int i = 0; i < _mVec.size(); ++i)
    {
        if(row < offset + _mVec[i]->getRows()) {
            if(col < _mVec[i]->getCols()) {
                return _mVec[i]->get(row - offset, col);
            } else {
                return 0;
            }
        }
        offset += _mVec[i]->getRows();
    }
    return 0;
}
void VerticalMatrixGroup::set(unsigned long row, unsigned long col, int val) {
    int offset = 0;
    for(int i = 0; i < _mVec.size(); ++i)
    {
        if(row < offset + _mVec[i]->getRows()) {
            if(col < _mVec[i]->getCols()) {
               _mVec[i]->set(row - offset, col, val);
               return;

            }
        }
        offset += _mVec[i]->getRows();
    }
}

void VerticalMatrixGroup::Draw() const {
    DrawBorder(this->getRows(), this->getCols());
    int offset = 0;
    for(auto& x : _mVec){
        x->iterate([this, offset](int row, int col, int val)->void {
           DrawItem(row + offset, col, val);
        });
        offset += x->getRows();
    }
}
void VerticalMatrixGroup::iterate(std::function<void (int,int,int)> func) const {
    int offset = 0;
    for(auto& x : _mVec) {
        x->iterate([offset, func](int row, int col, int val)->void {
           func(row + offset, col, val);
        });
    offset += x->getRows();
    }
}

void VerticalMatrixGroup::Add(std::shared_ptr<AMatrix> matrix) {
    _mVec.push_back(matrix);
}

void VerticalMatrixGroup::setDrawer(IDrawer* d) {
    AMatrix::setDrawer(d);
    for(auto& x : _mVec)
        x->setDrawer(d);
}

