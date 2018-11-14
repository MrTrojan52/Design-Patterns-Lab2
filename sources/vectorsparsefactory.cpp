#include "headers/vectorsparsefactory.h"

IVector* VectorSparseFactory::createVector(unsigned long size) const {
    return new VectorSparse(size);
}
