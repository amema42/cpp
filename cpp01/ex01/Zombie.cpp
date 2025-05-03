#include "Zombie.hpp"
#include <iostream>

// default constructor: initialize with empty name. -> Default template
Zombie::Zombie(void) : name("") {}

// "Parameterized" Constructor: init with given name. -> Not default template, but "custom"
Zombie::Zombie(std::string name) : name(name) {
    std::cout << "Zombie " << this->name << " created" << std::endl;
}

Zombie::~Zombie() {
    std::cout << "Zombie " << this->name << " destroyed" << std::endl;
}

// announce(): output signature message.
void Zombie::announce(void) const {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

// setName(): update name
void Zombie::setName(std::string name) {
    this->name = name;
}