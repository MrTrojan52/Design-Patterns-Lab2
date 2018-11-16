#ifndef VERTICALMATRIXGROUP_H
#define VERTICALMATRIXGROUP_H
#include "AMatrix.h"
class VerticalMatrixGroup : public AMatrix {
private:
    std::vector<std::shared_ptr<AMatrix>> _mVec;
public:
    VerticalMatrixGroup(std::vector<std::shared_ptr<AMatrix>> list):_mVec(list) {}
    unsigned long getRows() const override ;
    unsigned long getCols() const override;
    int get(unsigned long row, unsigned long col) const override;
    void set(unsigned long row, unsigned long col, int val) override;
    void setDrawer(IDrawer* d) override;
    void Draw() const override;
    void iterate(std::function<void (int,int,int)>) const override;
    void Add(std::shared_ptr<AMatrix> matrix);
};

#endif // VERTICALMATRIXGROUP_H
