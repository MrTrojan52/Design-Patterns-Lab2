//
// Created by trojan52 on 06.10.18.
//

#ifndef LAB1_2_AMATRIX_H
#define LAB1_2_AMATRIX_H

#include "IMatrix.h"
#include "IVector.h"
#include <vector>
#include "VectorNormal.h"
#include "idrawer.h"
class AMatrix: public IMatrix {
public:
    AMatrix(unsigned long rows, unsigned long cols, AMatrix* matrix, IDrawer *d) {
        this->data.resize(rows);
        for(unsigned long i = 0; i < rows; ++i)
            this->data[i] = matrix->createVector(cols);
        delete matrix;
        this->drawer = d;
    }
    virtual ~AMatrix() override{
        for(unsigned long i = 0; i < data.size(); ++i) {
            delete data[i];
        }
    }
    unsigned long getRows() const override ;
    unsigned long getCols() const override;
    int get(unsigned long row, unsigned long col) const override;
    void set(unsigned long row, unsigned long col, int val) override;
    IMatrix* getComponent() override;
    void setDrawer(IDrawer *d) override;
protected:
    AMatrix() = default;
    virtual IVector* createVector(unsigned long size) const = 0;
    virtual void DrawBorder(unsigned long rows, unsigned long cols) const;
    virtual void DrawItem(unsigned long row, unsigned long col, int val) const;

private:
    std::vector<IVector*> data;
    IDrawer *drawer;
};


#endif //LAB1_2_AMATRIX_H
