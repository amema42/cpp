#include "Weapon.hpp"

// Constructor: initializes weapon "type".
Weapon::Weapon(const std::string& initialType)
    : type(initialType)
{}

// return: current weapon type.
const std::string& Weapon::getType() const {
    return type;
}

// update: weapon "type"
void Weapon::setType(const std::string& newType) {
    type = newType;
}
