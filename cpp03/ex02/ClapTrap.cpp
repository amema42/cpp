#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name)
  : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " constructed\n";
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << _name << " destructed\n";
}

void ClapTrap::attack(const std::string& target) {
    if (_hitPoints == 0 || _energyPoints == 0) {
        std::cout << "ClapTrap " << _name
                  << " cannot attack (no HP or EP left)\n";
        return;
    }
    --_energyPoints;
    std::cout << "ClapTrap " << _name
              << " attacks " << target
              << ", causing " << _attackDamage
              << " points of damage! (EP left: " << _energyPoints << ")\n";
}

void ClapTrap::takeDamage(unsigned int amount) {
    unsigned int damage = std::min(amount, _hitPoints);
    _hitPoints -= damage;
    std::cout << "ClapTrap " << _name
              << " takes " << damage
              << " damage! (HP left: " << _hitPoints << ")\n";
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_hitPoints == 0 || _energyPoints == 0) {
        std::cout << "ClapTrap " << _name
                  << " cannot repair (no HP or EP left)\n";
        return;
    }
    --_energyPoints;
    _hitPoints += amount;
    std::cout << "ClapTrap " << _name
              << " repairs " << amount
              << " hit points! (HP: " << _hitPoints
              << ", EP left: " << _energyPoints << ")\n";
}
