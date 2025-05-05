#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& name)
  : ClapTrap(name + "_clap_name")  // nome del ClapTrap interno
  , ScavTrap(name)
  , FragTrap(name)
  , _name(name)
{
    _hitPoints    = FragTrap::_hitPoints;
    _energyPoints = ScavTrap::_energyPoints;
    _attackDamage = FragTrap::_attackDamage;

    std::cout << "DiamondTrap " << _name << " constructed\n";
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << _name << " destructed\n";
}

// ScavTrap::attack
void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void) {
    std::cout << "DiamondTrap name: " << _name
              << ", ClapTrap name: " << ClapTrap::_name
              << "\n";
}
