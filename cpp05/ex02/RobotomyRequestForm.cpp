#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 75), _target(target){
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other){
    this->_target = other._target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other){
    if (this != &other)
        this->_target = other._target;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){ }
    
void RobotomyRequestForm::execute(Bureaucrat const& executor) const{
    if (!getIsSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::cout << "[ * drilling noises * ]" << std::endl;
    //srand(time(NULL));
    if (rand() % 2 == 0)
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << _target << " robotomy failed." << std::endl;
}