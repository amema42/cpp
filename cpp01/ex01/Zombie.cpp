#include "Zombie.hpp"
#include <iostream>

// Default constructor: lascia name vuoto
Zombie::Zombie(void) : name("") {}

Zombie::Zombie(std::string name) : name(name) {
    std::cout << "Zombie " << this->name << " created" << std::endl;
}

// Destructor
Zombie::~Zombie() {
    std::cout << "Zombie " << this->name << " destroyed" << std::endl;
}

// announce()
void Zombie::announce(void) const {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

// Setter per il nome
void Zombie::setName(std::string name) {
    this->name = name;
}