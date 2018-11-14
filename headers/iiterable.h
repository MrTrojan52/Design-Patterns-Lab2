#ifndef IITERABLE_H
#define IITERABLE_H
#include <functional>
class IIterable {
public:
    virtual void iterate(std::function<void (int,int,int)>) const = 0;
    virtual ~IIterable() = default;
};

#endif // IITERABLE_H
