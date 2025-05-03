#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void   randomChump(std::string name);

int main() {
    // Allocate -> heap Zombie
    Zombie* heapZombie = newZombie("HeapZombie");
    // Call announce()
    heapZombie->announce();
    // Free -> heap Zombie
    delete heapZombie;

    // Stack allocation; auto announce -> "Zombie"
    randomChump("StackZombie");
    return 0;
}
