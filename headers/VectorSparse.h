//
// Created by trojan52 on 06.10.18.
//

#ifndef LAB1_2_VECTORSPARSE_H
#define LAB1_2_VECTORSPARSE_H

#include "IVector.h"
#include <unordered_map>
#include <stdexcept>

class VectorSparse: public IVector {
public:
    explicit VectorSparse(unsigned long size) {
        this->_size = size;
    }
    unsigned long getSize() const override;
    int get(unsigned long pos) const override;
    void set(unsigned long pos, int val) override;
private:
    std::unordered_map<unsigned long, int> data;
    unsigned long _size;
};


#endif //LAB1_2_VECTORSPARSE_H
