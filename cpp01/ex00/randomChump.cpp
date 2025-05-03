#include "Zombie.hpp"

// randomChump: create: stack Zombie, call announce, auto-destroy.
void randomChump(std::string name) {
    Zombie z(name);   // create Zombie on "stack"
    z.announce();     // Execute announce method
}
