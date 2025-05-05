#include "ClapTrap.hpp"

int main()
{
    ClapTrap ct("amema");

    ct.attack("peer-Evaluator 1");
    ct.takeDamage(5);
    ct.beRepaired(3);
    ct.takeDamage(20);
    ct.attack("peer-Evaluator 2"); //subject:: Of course, ClapTrap can’t do anything if it has no hit points or energy points left.

    return 0;
}

// subject: ClapTrap <name> attacks <target>, causing <damage> points of damage!