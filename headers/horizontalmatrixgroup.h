#ifndef HORIZONTALMATRIXGROUP_H
#define HORIZONTALMATRIXGROUP_H
#include "AMatrix.h"
class HorizontalMatrixGroup : public AMatrix {
private:
    std::vector<AMatrix*> _mVec;
public:
    HorizontalMatrixGroup(std::vector<AMatrix*> list) {
        this->_mVec = list;
    }
    unsigned long getRows() const override ;
    unsigned long getCols() const override;
    int get(unsigned long row, unsigned long col) const override;
    void set(unsigned long row, unsigned long col, int val) override;
    void setDrawer(IDrawer *d) override;
    void Draw() const override;
    void iterate(std::function<void (int,int,int)>) const override;
    void Add(AMatrix* matrix);
};

#endif // HORIZONTALMATRIXGROUP_H
