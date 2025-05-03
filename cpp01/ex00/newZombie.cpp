#include "Zombie.hpp"

// newZombie: dynamically allocates a Zombie on the heap.

Zombie* newZombie(std::string name) {
    // Allocate: a Zombie obj on the "heap"
    Zombie* z = new Zombie(name);
    return z;
}
