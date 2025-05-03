#include "Zombie.hpp"

// Se N<=0 restituiamo NULL (o nullptr su C++11+)
Zombie* zombieHorde(int N, std::string name) {
    if (N <= 0)
        return NULL;

    // 1) Alloca un array di N Zombie (chiamerà default ctor per ciascuno)
    Zombie* horde = new Zombie[N];

    // 2) Imposta il nome a tutti gli zombie
    for (int i = 0; i < N; ++i)
        horde[i].setName(name);

    // 3) Restituisce il puntatore al primo elemento
    return horde;
}