// newZombie.cpp

#include "Zombie.hpp"   // Dichiarazione della classe Zombie

// newZombie: crea un singolo Zombie sull’heap
Zombie* newZombie(std::string name) {
    // 1) Allochiamo dinamicamente un oggetto Zombie:  ‘name’
    Zombie* z = new Zombie(name);
    // 2) Restituiamo il puntatore per poterlo usare (e poi delete)
    return z;
}
