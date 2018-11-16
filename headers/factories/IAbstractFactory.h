#ifndef IABSTRACTFACTORY_H
#define IABSTRACTFACTORY_H
#include <memory>
#include "../AMatrix.h"
#include "../idrawer.h"
#include "../horizontalmatrixgroup.h"
#include "../verticalmatrixgroup.h"
class IAbstractFactory {
public:
    virtual std::shared_ptr<AMatrix> create_normal(unsigned long r, unsigned long c, IDrawer * d) const = 0;
    virtual std::shared_ptr<AMatrix> create_and_fill_normal(unsigned long r, unsigned long c, IDrawer * d, unsigned long nonZeroCount, int maxValue) const = 0;
    virtual std::shared_ptr<AMatrix> create_sparse(unsigned long r, unsigned long c, IDrawer * d) const = 0;
    virtual std::shared_ptr<AMatrix> create_and_fill_sparse(unsigned long r, unsigned long c, IDrawer * d, unsigned long nonZeroCount, int maxValue) const = 0;
    virtual std::shared_ptr<HorizontalMatrixGroup> create_horizontal_group(std::vector<std::shared_ptr<AMatrix>> g) const = 0;
    virtual std::shared_ptr<VerticalMatrixGroup> create_vertical_group(std::vector<std::shared_ptr<AMatrix>> g) const = 0;
    virtual ~IAbstractFactory() = default;
};


#endif
