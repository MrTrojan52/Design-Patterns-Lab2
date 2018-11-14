#ifndef VECTORSPARSEFACTORY_H
#define VECTORSPARSEFACTORY_H
#include "ivectorfactory.h"
#include "VectorSparse.h"
class VectorSparseFactory : public IVectorFactory {
public:
    IVector* createVector(unsigned long size) const override;
};

#endif // VECTORSPARSEFACTORY_H
