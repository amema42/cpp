#include "Dog.hpp"

Dog::Dog() {
    type = "Dog";
    std::cout << "Dog created\n";
}

Dog::~Dog() {
    std::cout << "Dog destroyed\n";
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Dog copied\n";
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog assigned\n";
    if (this != &other)
        Animal::operator=(other);
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Woof woof!\n";
}
