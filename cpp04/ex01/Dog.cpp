#include "Dog.hpp"

Dog::Dog() {
    type = "Dog";
    this->brain = new Brain(); /*(brain) Alloc brain*/
    std::cout << "Dog created\n";
}

Dog::~Dog() {
    delete brain; // (brain) free allocated memory
    std::cout << "Dog destroyed\n";
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Dog copied\n";
    this->brain = new Brain(*other.brain); /*(brain) deep copy of brain*/
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog assigned\n";
    if (this != &other)
    {
        Animal::operator=(other);
        if (this->brain)
            delete this->brain; // Delete existing (brain)
        brain = new Brain(*other.brain);
    }
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Woof woof!\n";
}

void Dog::setIdea(int index, const std::string& idea) {
    brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const {
    return brain->getIdea(index);
}