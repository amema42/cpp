#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string& name)
    : name(name), weapon(NULL)
{}

void HumanB::setWeapon(Weapon& w) { // uso un puntatore perché HumanB può stare senza arma -> setWeapon()
    weapon = &w;
}

void HumanB::attack() const {
    if (weapon)
        std::cout << name
                  << " attacks with their "
                  << weapon->getType()
                  << std::endl;
    else
        std::cout << name << " has no weapon" << std::endl;
}
