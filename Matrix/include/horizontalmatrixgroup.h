#ifndef HORIZONTALMATRIXGROUP_H
#define HORIZONTALMATRIXGROUP_H
#include "AMatrix.h"
class HorizontalMatrixGroup : public AMatrix {
private:
    std::vector<std::shared_ptr<AMatrix>> _mVec;
public:
    HorizontalMatrixGroup(std::vector<std::shared_ptr<AMatrix>> list):_mVec(list) { }
    unsigned long getRows() const override ;
    unsigned long getCols() const override;
    int get(unsigned long row, unsigned long col) const override;
    void set(unsigned long row, unsigned long col, int val) override;
    void Draw() const override;
    void setDrawer(IDrawer* d) override;
    void iterate(std::function<void (int,int,int)>) const override;
    void Add(std::shared_ptr<AMatrix> matrix);
};

#endif // HORIZONTALMATRIXGROUP_H
