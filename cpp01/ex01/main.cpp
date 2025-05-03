#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main() {
    int N = 5;
    // create: 5 zombies w. name "MoarZombie"
    Zombie* horde = zombieHorde(N, "MoarZombie");

    // Call announce() on each zombie: obv Annauncing a Walking Dead Zombie :)
    for (int i = 0; i < N; ++i)
        horde[i].announce();

    // deallocate the zombie array
    delete[] horde;

    return 0;
}
