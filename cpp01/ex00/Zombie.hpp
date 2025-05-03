#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>  // per std::string

class Zombie {
private:
    std::string name;  // zombie's name

public:
    // Costruttore: inizializza 'name' col valore passato
    Zombie(std::string name);

    // Distruttore: stamperà un messaggio di debug alla distruzione
    ~Zombie();

    // announce(): non modifica l'oggetto, quindi lo dichiariamo const
    void announce(void) const;
};

#endif
