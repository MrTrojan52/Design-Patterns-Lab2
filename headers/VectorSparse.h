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
    explicit VectorSparse(long size) {
        if(size >= 0 )
            this->_size = size;
        else
            throw std::invalid_argument("Size must be >= 0");

    }
    unsigned long getSize() const override;
    int get(int pos) const override;
    void set(int pos, int val) override;
private:
    std::unordered_map<int, int> data;
    unsigned long _size;
};


#endif //LAB1_2_VECTORSPARSE_H
