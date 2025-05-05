#include "DiamondTrap.hpp"

int main() {
    DiamondTrap dt("Marvin");

    dt.attack("VibeCoder");
    dt.takeDamage(50);
    dt.beRepaired(40);
    dt.highFivesGuys();   // here: FragTrap
    dt.guardGate();       // here: ScavTrap
    dt.whoAmI();          // DiamondTrap, current class

    return 0;
}


// int main() {
//     FragTrap ft("<<Bombardiro Crocodilo>>");

//     // Costructor: ClapTrap -> FragTrap
//     ft.attack("<<Tung tung tung tung tung tung tung tung tung sahur>>");
//     ft.takeDamage(40);
//     ft.beRepaired(20);
//     ft.highFivesGuys();

//     // (1) FragTrap::~FragTrap() -> ClapTrap::~ClapTrap()
//     return 0;
// }

// int main() {
//     ScavTrap st("Gino");

//     st.attack("Pino");
//     st.guardGate();
//     st.takeDamage(30);
//     st.beRepaired(15);

//     return 0;
// }


// int main()
// {
//     ClapTrap ct("amema");

//     ct.attack("peer-Evaluator 1");
//     ct.takeDamage(5);
//     ct.beRepaired(3);
//     ct.takeDamage(20);
//     ct.attack("peer-Evaluator 2");

//     return 0;
// }
