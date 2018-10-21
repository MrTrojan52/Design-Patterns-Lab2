//
// Created by trojan52 on 06.10.18.
//

#ifndef LAB1_2_VECTORNORMAL_H
#define LAB1_2_VECTORNORMAL_H

#include "IVector.h"
#include <vector>
#include <stdexcept>

class VectorNormal: public IVector {
public:
    explicit VectorNormal(long size) {
        if(size >= 0 )
            this->data.resize(size);
        else
            throw std::invalid_argument("Size must be >= 0");

    }
    unsigned long getSize() const override;
    int get(int pos) const override;
    void set(int pos, int val) override;
private:
    std::vector<int> data;
};


#endif //LAB1_2_VECTORNORMAL_H
