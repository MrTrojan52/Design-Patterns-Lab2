#ifndef IVECTORFACTORY_H
#define IVECTORFACTORY_H
#include "IVector.h"
class IVectorFactory {
public:
    virtual IVector* createVector(unsigned long size) const = 0;
    virtual ~IVectorFactory() = default;
};

#endif // IVECTORFACTORY_H
