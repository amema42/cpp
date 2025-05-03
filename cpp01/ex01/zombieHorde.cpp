#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    if (N <= 0)
        return NULL;

    // alloc array of N zombies
    Zombie* horde = new Zombie[N];

    // set zombie names
    for (int i = 0; i < N; ++i)
        horde[i].setName(name);

    // ret * to the "array"
    return horde;
}