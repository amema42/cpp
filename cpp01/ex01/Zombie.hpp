#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>  // std::string lib

class Zombie {
private:
    std::string name;  // (0)

public:
    Zombie(void);
    // init name (1)
    Zombie(std::string name);
    ~Zombie(void);

    // announce() : no "object" modification
    void announce(void) const;
    // set new Name (2)
    void setName(std::string name);
};

#endif
