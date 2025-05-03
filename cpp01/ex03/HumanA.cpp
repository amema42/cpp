#include "HumanA.hpp"

// Constructor: init 1. name and 2. weapon "reference"
HumanA::HumanA(const std::string& name, Weapon& weapon)
    : name(name), weapon(weapon)
{}

// attack: outputs formatted attack message.
void HumanA::attack() const {
    std::cout << name
              << " attacks with their "
              << weapon.getType()
              << std::endl;
}