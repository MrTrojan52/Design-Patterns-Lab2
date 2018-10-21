//
// Created by trojan52 on 06.10.18.
//

#include "headers/VectorNormal.h"


unsigned long VectorNormal::getSize() const {
    return this->data.size();
}

int VectorNormal::get(int pos) const {
    return this->data.at(pos);
}

void VectorNormal::set(int pos, int val) {
    this->data.at(pos) = val;
}
