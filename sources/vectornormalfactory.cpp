#include "headers/vectornormalfactory.h"


IVector* VectorNormalFactory::createVector(unsigned long size) const {
    return new VectorNormal(size);
}
