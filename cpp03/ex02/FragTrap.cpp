#include "FragTrap.hpp"

// Constructor: first call ClapTrap(name), then override values and output a message
FragTrap::FragTrap(const std::string& name)
  : ClapTrap(name)
{
    _hitPoints    = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << _name << " constructed\n";
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << _name << " destructed\n";
}

// Optional: custom re-implementation of attack()
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

// New method: highFivesGuys
void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << _name
              << " requests a positive high five!\n";
}