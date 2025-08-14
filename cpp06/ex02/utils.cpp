#include <cstdlib>
#include <ctime>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

// randomly generates A, B or C obj
Base* generate() {
    int r = rand() % 3; // 0, 1 or 2
    switch (r) {
        case 0:
            std::cout << "Generated A" << std::endl;
            return new A();
        case 1:
            std::cout << "Generated B" << std::endl;
            return new B();
        default:
            std::cout << "Generated C" << std::endl;
            return new C();
    }
}

// identifies via pointer
void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

// identifies via reference (without <typeinfo>)
void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (...) {} // catches any exception

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (...) {}
}
