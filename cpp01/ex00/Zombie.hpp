#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>  // std::string
#include <iostream>

class Zombie {
private:
    std::string name;  // zombie "name"

public:
    // Constructor: initialize 'name'
    Zombie(std::string name);

    ~Zombie();

    // announce(): const method, does not alter "object"
    void announce(void) const;
};

#endif
