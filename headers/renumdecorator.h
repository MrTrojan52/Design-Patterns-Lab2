#ifndef RENUMDECORATOR_H
#define RENUMDECORATOR_H
#include "IMatrix.h"

class RenumDecorator : public IMatrix {
public:
    RenumDecorator(IMatrix * m) {
        this->_matrix = m;

    }
    unsigned long getRows() const override ;
    unsigned long getCols() const override;
    int get(unsigned long row, unsigned long col) const override;
    void set(unsigned long row, unsigned long col, int val) override;
    IMatrix* getComponent() override;
    void Draw() const override;
    void swapCols(int c1, int c2);
    void swapRows(int r1, int r2);
private:
    IMatrix * _matrix;
    int swapCol1 = -1;
    int swapCol2 = -1;
    int swapRow1 = -1;
    int swapRow2 = -1;
};

#endif // RENUMDECORATOR_H
