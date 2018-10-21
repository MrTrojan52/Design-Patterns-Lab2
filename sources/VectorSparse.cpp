//
// Created by trojan52 on 06.10.18.
//

#include "headers/VectorSparse.h"


unsigned long VectorSparse::getSize() const {
    return this->_size;
}

int VectorSparse::get(int pos) const {
    if(pos < 0 || pos > this->_size - 1)
        throw std::out_of_range("VectorSparse::get pos out of range");
    if(this->data.find(pos) != this->data.end())
        return this->data.at(pos);
    else
        return 0;
}

void VectorSparse::set(int pos, int val) {
    if(pos < 0 || pos > this->_size - 1)
        throw std::out_of_range("VectorSparse::set pos out of range");
    if(val) {
        this->data[pos] = val;
    } else {
        this->data.erase(pos); // delete element if exists
    }

}
