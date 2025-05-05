#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
    private:
        std::string _name;  // *_same* in ClapTrap
    
    public:
        DiamondTrap(const std::string& name);
        ~DiamondTrap();
    
        // using l'attack() from ScavTrap
        void attack(const std::string& target);

        void whoAmI(void);
    };

#endif