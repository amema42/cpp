#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"


Intern::Intern(){}
Intern::Intern(const Intern& other){
    (void)other;
}
Intern& Intern::operator=(const Intern& other){
    if (this != &other)
        *this = other;
    return *this;
}

Intern::~Intern(){}

AForm* Intern::makeForm(const std::string& formName, const std::string& target){
    if (formName == "robotomy request"){
        std::cout << "Intern creates RobotomyRequestForm" << std::endl;
        return new RobotomyRequestForm(target);
    }
    else if (formName == "presidential pardon"){
        std::cout << "Intern creates PresidentialPardonForm" << std::endl;
        return new PresidentialPardonForm(target);
    }
    else if (formName == "shrubbery creation"){
        std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
        return new ShrubberyCreationForm(target);
    }
    else {
        std::cerr << "Intern: Error - unknown form name \"" << formName << "\"" << std::endl;
        return NULL;
    }
}