#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main() {
    int N = 5;
    // Creo 5 zombie “MoarZombie”
    Zombie* horde = zombieHorde(N, "MoarZombie");

    // Li faccio annunciare tutti
    for (int i = 0; i < N; ++i)
        horde[i].announce();

    // Dealloco correttamente l’array
    delete[] horde;

    return 0;
}
