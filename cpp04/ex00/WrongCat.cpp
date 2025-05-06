#include "WrongCat.hpp"

WrongCat::WrongCat() {
    type = "WrongCat";
    std::cout << "WrongCat created\n";
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destroyed\n";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    std::cout << "WrongCat copied\n";
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    std::cout << "WrongCat assigned\n";
    if (this != &other)
        WrongAnimal::operator=(other);
    return *this;
}

void WrongCat::makeSound() const {
    std::cout << "Meow?? But wrongMEOWWWWWWWW!\n";
}