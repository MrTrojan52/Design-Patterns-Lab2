//
// Created by trojan52 on 06.10.18.
//

#include "headers/VectorNormal.h"


unsigned long VectorNormal::getSize() const {
    return this->data.size();
}

int VectorNormal::get(unsigned long pos) const {
    return this->data.at(pos);
}

void VectorNormal::set(unsigned long pos, int val) {
    this->data.at(pos) = val;
}
