#include <iostream>

#include "dirty_hacks.hpp"

class base
{
    int x_ = 0;

public:
    int x() { return x_; }
}; // class base

class derived1 : public base
{
    int x_ = 1;

public:
    int x() { return x_; }
}; // class derived1

class derived2 : public base
{
    int x_ = 2;

public:
    int x() { return x_; }
}; // class derived2

HIJACKER(base, x_, int);
HIJACKER(derived1, x_, int);

int main()
{
    derived1 d1;
    derived2 d2;
    base &b1 = d1;
    base &b2 = d2;
    std::cout << "(" << b1.x() << ", " << d1.x() << "), (" << b2.x() << ", " << d2.x() << ")\n";
    HIJACK(&b1, x_) = HIJACK(&b2, x_) = 233;
    std::cout << "(" << b1.x() << ", " << d1.x() << "), (" << b2.x() << ", " << d2.x() << ")\n";
    HIJACK(&d1, x_) = HIJACK(&d2, x_) = 666;
    std::cout << "(" << b1.x() << ", " << d1.x() << "), (" << b2.x() << ", " << d2.x() << ")" << std::endl;
}