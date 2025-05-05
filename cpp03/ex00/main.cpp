#include "ClapTrap.hpp"

int main()
{
    ClapTrap ct("amema");

    ct.attack("peer-Evaluator 1");
    ct.takeDamage(5);
    ct.beRepaired(3);
    ct.takeDamage(20);
    ct.attack("peer-Evaluator 2");

    return 0;
}

// subject: ClapTrap <name> attacks <target>, causing <damage> points of damage!