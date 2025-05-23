#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
private:
    std::string type;  // weapon type

public:
    Weapon(const std::string& initialType);
    const std::string& getType() const;
    void setType(const std::string& newType);
};

#endif