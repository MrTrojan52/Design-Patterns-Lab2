#ifndef MATRIXFACTORY_H
#define MATRIXFACTORY_H
#include "IAbstractFactory.h"

class MatrixFactory : public IAbstractFactory {
public:
    virtual std::shared_ptr<AMatrix> create_and_fill_normal(unsigned long r, unsigned long c, IDrawer * d, unsigned long nonZeroCount, int maxValue) const override;
    virtual std::shared_ptr<AMatrix> create_and_fill_sparse(unsigned long r, unsigned long c, IDrawer * d, unsigned long nonZeroCount, int maxValue) const override;
    virtual std::shared_ptr<AMatrix> create_normal(unsigned long r, unsigned long c, IDrawer * d) const override;
    virtual std::shared_ptr<AMatrix> create_sparse(unsigned long r, unsigned long c, IDrawer * d) const override;
    virtual std::shared_ptr<HorizontalMatrixGroup> create_horizontal_group(std::vector<std::shared_ptr<AMatrix>> g) const override;
    virtual std::shared_ptr<VerticalMatrixGroup> create_vertical_group(std::vector<std::shared_ptr<AMatrix>> g) const override;
};

#endif // MATRIXFACTORY_H
