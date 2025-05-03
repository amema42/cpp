#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB {
private:
    std::string name;
    Weapon*    weapon;  // nullable pointer:
                        // can be unarmed (null) or armed (not null)

public:
    HumanB(const std::string& name);
    void   setWeapon(Weapon& weapon);
    void   attack() const;
};

#endif
