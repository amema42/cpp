#include "Zombie.hpp"   // Dichiarazione della classe Zombie

// randomChump: crea uno Zombie sullo stack, lo fa annunciare e
// poi lo distrugge automaticamente quando esce dalla funzione
void randomChump(std::string name) {
    // 1) Dichiarazione di uno Zombie “locale” sullo stack
    Zombie z(name);
    // 2) Chiamata al metodo announce()
    z.announce();
    // 3) Alla fine di questo scope (’}’) verrà chiamato il distruttore
    //    e la memoria sullo stack verrà liberata automaticamente.
}