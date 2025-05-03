#include "Zombie.hpp"

// Constructor: initialize zombie with provided name.
Zombie::Zombie(std::string name) : name(name) {
    std::cout << "Zombie " << this->name << " created" << std::endl;
}

// Destructor: "cleanup" and log destruction
Zombie::~Zombie() {
    std::cout << "Zombie " << this->name << " destroyed" << std::endl;
}

// announce: print a zombie's msg .
void Zombie::announce(void) const {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}