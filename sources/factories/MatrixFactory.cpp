#include "headers/factories/matrixfactory.h"
#include "headers/MatrixNormal.h"
#include "headers/MatrixSparse.h"
#include "headers/MatrixInitiator.h"
#include "headers/horizontalmatrixgroup.h"
#include "headers/verticalmatrixgroup.h"
std::shared_ptr<AMatrix> MatrixFactory::create_and_fill_normal(unsigned long r, unsigned long c, IDrawer * d, unsigned long nonZeroCount, int maxValue) const {
    std::shared_ptr<MatrixNormal> matrix(new MatrixNormal(r,c,d));
    MatrixInitiator::fillMatrix(matrix, nonZeroCount, maxValue);
    return matrix;
}

std::shared_ptr<AMatrix> MatrixFactory::create_and_fill_sparse(unsigned long r, unsigned long c, IDrawer * d, unsigned long nonZeroCount, int maxValue) const {
    std::shared_ptr<MatrixSparse> matrix(new MatrixSparse(r,c,d));
    MatrixInitiator::fillMatrix(matrix, nonZeroCount, maxValue);
    return matrix;
}


std::shared_ptr<AMatrix> MatrixFactory::create_normal(unsigned long r, unsigned long c, IDrawer * d) const {
    return  std::shared_ptr<MatrixNormal>(new MatrixNormal(r, c, d));
}

std::shared_ptr<AMatrix> MatrixFactory::create_sparse(unsigned long r, unsigned long c, IDrawer * d) const {
    return  std::shared_ptr<MatrixSparse>(new MatrixSparse(r, c, d));
}

std::shared_ptr<HorizontalMatrixGroup> MatrixFactory::create_horizontal_group(std::vector<std::shared_ptr<AMatrix>> g) const {
    return std::shared_ptr<HorizontalMatrixGroup>(new HorizontalMatrixGroup(g));
}

std::shared_ptr<VerticalMatrixGroup> MatrixFactory::create_vertical_group(std::vector<std::shared_ptr<AMatrix>> g) const {
    return std::shared_ptr<VerticalMatrixGroup>(new VerticalMatrixGroup(g));
}
