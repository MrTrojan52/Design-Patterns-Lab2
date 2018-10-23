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
    explicit VectorNormal(unsigned long size) {
            this->data.resize(size);
    }
    unsigned long getSize() const override;
    int get(unsigned long pos) const override;
    void set(unsigned long pos, int val) override;
private:
    std::vector<int> data;
};


#endif //LAB1_2_VECTORNORMAL_H
