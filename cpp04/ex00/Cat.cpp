#include "Cat.hpp"

Cat::Cat() {
    type = "Cat";
    std::cout << "Cat created\n";
}

Cat::~Cat() {
    std::cout << "Cat destroyed\n";
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat copied\n";
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat assigned\n";
    if (this != &other)
        Animal::operator=(other);
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meow meow!\n";
}