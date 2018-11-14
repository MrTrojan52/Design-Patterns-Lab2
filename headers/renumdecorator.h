#ifndef RENUMDECORATOR_H
#define RENUMDECORATOR_H
#include "AMatrix.h"
class RenumDecorator: public AMatrix {
public:
    RenumDecorator(std::shared_ptr<AMatrix>& matrix) {
        this->_matrix = matrix;
    }
    unsigned long getRows() const override;
    unsigned long getCols() const override;
    int get(unsigned long, unsigned long) const override;
    void set(unsigned long, unsigned long, int) override;
    void Draw() const override;
    void setDrawer(IDrawer* d) override;
    std::shared_ptr<AMatrix> getComponent() override;
    void swapCols(int c1, int c2);
    void swapRows(int r1, int r2);
    void iterate(std::function<void (int,int,int)>) const override;
    std::tuple<int,int> getSwapped(int row, int col) const;
private:    
    std::shared_ptr<AMatrix> _matrix;
    int swapCol1 = -1;
    int swapCol2 = -1;
    int swapRow1 = -1;
    int swapRow2 = -1;
};

#endif // RENUMDECORATOR_H
