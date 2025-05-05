#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name)
  : ClapTrap(name)
{
    _hitPoints    = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << _name << " constructed\n";
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << _name << " destructed\n";
}

void ScavTrap::attack(const std::string& target) {
    if (_hitPoints == 0 || _energyPoints == 0) {
        std::cout << "ScavTrap " << _name
                  << " cannot attack (no HP or EP left)\n";
        return;
    }
    --_energyPoints;
    std::cout << "ScavTrap " << _name
              << " attacks " << target
              << ", causing " << _attackDamage
              << " points of damage! (EP left: " << _energyPoints << ")\n";
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << _name
              << " is now in Gate keeper mode\n";
}
