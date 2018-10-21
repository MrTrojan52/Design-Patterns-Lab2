//
// Created by trojan52 on 10.10.18.
//

#include "headers/MatrixSparse.h"

IVector* MatrixSparse::createVector(long size) const {
    return new VectorSparse(size);
}
