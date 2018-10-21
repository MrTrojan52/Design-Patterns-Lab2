//
// Created by trojan52 on 06.10.18.
//

#ifndef LAB1_2_IVECTOR_H
#define LAB1_2_IVECTOR_H

class IVector {
public:
    virtual unsigned long getSize() const = 0;
    virtual int get(int) const = 0;
    virtual void set(int, int) = 0;
};


#endif //LAB1_2_IVECTOR_H
