#ifndef RENUMDECORATOR_H
#define RENUMDECORATOR_H
#include "IMatrix.h"
#include <tuple>
class RenumDecorator : public IMatrix, public IDrawer{
public:
    RenumDecorator(IMatrix * m, IDrawer * d) {
        this->_matrix = m;
        this->_mdrawer = d;

    }
    unsigned long getRows() const override ;
    unsigned long getCols() const override;
    int get(unsigned long row, unsigned long col) const override;
    void set(unsigned long row, unsigned long col, int val) override;
    IMatrix* getComponent() override;
    void Draw() override;
    void setDrawer(IDrawer* d) override;
    void swapCols(int c1, int c2);
    void swapRows(int r1, int r2);
protected:
    void DrawBorder(unsigned long rows, unsigned long cols) override;
    void DrawItem(unsigned long row, unsigned long col, int val) const override;
private:    
    std::tuple<int,int> getSwapped(int row, int col) const;
    IMatrix * _matrix;
    IDrawer * _mdrawer;
    int swapCol1 = -1;
    int swapCol2 = -1;
    int swapRow1 = -1;
    int swapRow2 = -1;
};

#endif // RENUMDECORATOR_H
