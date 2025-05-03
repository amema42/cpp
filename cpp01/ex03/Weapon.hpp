#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
private:
    std::string type;  // tipo d’arma

public:
    Weapon(const std::string& initialType);
    const std::string& getType() const;
    void setType(const std::string& newType);
};

#endif // WEAPON_HPP