#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    try {
        Intern someRandomIntern;
        Bureaucrat boss("The Boss", 1);

        AForm* shrub = someRandomIntern.makeForm("shrubbery creation", "Home");
        AForm* robot = someRandomIntern.makeForm("robotomy request", "Bender");
        AForm* pardon = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");
        AForm* unknown = someRandomIntern.makeForm("useless form", "Nobody");

        if (shrub) {
            boss.signForm(*shrub);
            boss.executeForm(*shrub);
            delete shrub;
        }

        if (robot) {
            boss.signForm(*robot);
            boss.executeForm(*robot);
            delete robot;
        }

        if (pardon) {
            boss.signForm(*pardon);
            boss.executeForm(*pardon);
            delete pardon;
        }

        if (unknown == NULL)
            std::cout << "Intern couldn't create unknown form!" << std::endl;

    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
