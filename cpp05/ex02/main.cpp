#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>


int main() {
    srand(time(NULL));
    try {
        // Bureaucrat with high enough grade to sign and execute
        Bureaucrat john("John", 1);

        // Create the form targeting "garden"
        ShrubberyCreationForm shrub("garden");

        // Try signing the form
        john.signForm(shrub);

        // Try executing the form
        john.executeForm(shrub);

        std::cout << "ShrubberyCreationForm executed successfully." << std::endl;
        std::cout << "Check for file: 'garden_shrubbery' in the working directory!" << std::endl;

    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    try {
        // Bureaucrat with high enough grade to sign and execute
        Bureaucrat john("John", 1);

        // Create the form targeting "garden"
        RobotomyRequestForm robot("Bender");
        RobotomyRequestForm robot1("Target-X");


        // Try signing the form
        john.signForm(robot);
        john.signForm(robot1);


        // Try executing the form
        john.executeForm(robot);
        john.executeForm(robot1);


        //std::cout << "ShrubberyCreationForm executed successfully." << std::endl;
        //std::cout << "Check for file: 'garden_shrubbery' in the working directory!" << std::endl;

    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "We Can Do Better about the UX" << std::endl;
    try {
        // Bureaucrat lowRank("Gianni", 150);
        //Bureaucrat toLowToExe("Gianni", 140);
        Bureaucrat doubleSign("Gato", 1);
        // RobotomyRequestForm f("Target");
        //ShrubberyCreationForm f ("toLowToExe");
        RobotomyRequestForm f("X");
        // lowRank.signForm(f);
        // lowRank.executeForm(f);
        //toLowToExe.signForm(f);
        //toLowToExe.executeForm(f);
        doubleSign.signForm(f);
        doubleSign.signForm(f);

        //doubleSign.executeForm(f);
        //doubleSign.executeForm(f);
        

    } catch (std::exception& e){
        std::cerr << "ERROR: signForm: " << e.what() << std::endl;
    }


    

    return 0;
}
