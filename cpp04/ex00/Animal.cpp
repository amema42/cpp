#include "Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "Animal (default constructor class) Created\n";
}

Animal::Animal(const Animal& other) : type(other.type) { // Copy constructor es: Animal a; << Animal a(b); >>
    std::cout << "Animal copied\n";
}

/*
Case Scenario: (1) Animal a; (2) Animal b; (3) a = b
& with: ((return *this;)) -> Another Case Scenario: (1) Animal a; (2) Animal a(b); Animal c; c = b
*/

Animal& Animal::operator=(const Animal& other) {
    std::cout << "Animal assigned\n";
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal destroyed\n";
}

// virtual func: can be overridden by derived classes AND returns animal type (string)
std::string Animal::getType() const {
    return type;
}

void Animal::makeSound() const {
    std::cout << "*generic FART*\n";
}