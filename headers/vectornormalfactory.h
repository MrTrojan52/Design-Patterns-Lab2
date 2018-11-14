#ifndef VECTORNORMALFACTORY_H
#define VECTORNORMALFACTORY_H
#include "ivectorfactory.h"
#include "VectorNormal.h"
class VectorNormalFactory : public IVectorFactory {
public:
    IVector* createVector(unsigned long size) const override;
};

#endif // VECTORNORMALFACTORY_H
