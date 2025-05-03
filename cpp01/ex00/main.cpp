// main.cpp
#include "Zombie.hpp"       // include della classe Zombie (e di <string>)

 // dichiarazioni delle funzioni definite in newZombie.cpp e randomChump.cpp
Zombie* newZombie(std::string name);
void   randomChump(std::string name);

int main() {
    // 1) Alloco uno Zombie sul heap con nome "HeapZombie"
    Zombie* heapZombie = newZombie("HeapZombie");
    // 2) Faccio annunciare lo zombie creato dinamicamente
    heapZombie->announce();
    // 3) Dealloco lo zombie per evitare memory leak
    delete heapZombie;

    // 4) Creo uno Zombie sullo stack e lo faccio annunciare:
    //    randomChump crea un oggetto locale, chiama announce() e
    //    quando esce dallo scope (fine funzione) il distruttore viene invocato automaticamente
    randomChump("StackZombie");

    // 5) Ritorno 0: indicazione di successo al sistema operativo
    return 0;
}
