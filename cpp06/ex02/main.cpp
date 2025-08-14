#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base* generate();
void identify(Base* p);
void identify(Base& p);

int main() {
    std::srand(std::time(NULL));
    int i = 0;
    while (i < 6) {
        Base* ptr = generate(); // create random object

        std::cout << "identify by pointer: " << std::endl;
        identify(ptr);

        std::cout << "identify by reference: " << std::endl;
        identify(*ptr);

        delete ptr;
        std::cout << "-----" << std::endl;
        i++;
    }

    return 0;
}
