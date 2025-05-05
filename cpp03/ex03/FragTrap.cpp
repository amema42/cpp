#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(const std::string& name)
  : ClapTrap(name)              // calling ClapTrap(name)
{
    _hitPoints    = 100;
    _energyPoints = 100;
    _attackDamage = 30;

    std::cout << "FragTrap " << _name << " constructed\n";
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << _name << " destructed\n";
}

void FragTrap::attack(const std::string& target) {
    if (_hitPoints == 0 || _energyPoints == 0) {
        std::cout << "FragTrap " << _name
                  << " cannot attack (no HP or EP left)\n";
        return;
    }
    --_energyPoints;
    std::cout << "FragTrap " << _name
              << " attacks " << target
              << ", causing " << _attackDamage
              << " points of damage! (EP left: " << _energyPoints << ")\n";
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << _name
              << " requests a positive high five!\n";
}
