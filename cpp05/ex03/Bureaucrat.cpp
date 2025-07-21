#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

//Bureaucrat::Bureaucrat(){}

Bureaucrat::Bureaucrat() : _name("Unnamed"), _grade(150){}

Bureaucrat::Bureaucrat(std::string const& name, int grade) : _name(name){
    if (grade < 1){
        throw GradeTooHighException();
    }
    if (grade > 150){
        throw GradeTooLowException();
    }
    this->_grade = grade;

}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade){}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){
    if (this != &other)
        this->_grade = other._grade;
    return *this;
}

Bureaucrat::~Bureaucrat(){}

const std::string& Bureaucrat::getName() const{
    return _name;
}

int Bureaucrat::getGrade() const{
    return _grade;
}


void Bureaucrat::setGradeUp(){
    if (_grade <= 1)
        throw GradeTooHighException();
    _grade -= 1;
}
void Bureaucrat::setGradeDown(){
    if (_grade >= 150)
        throw GradeTooLowException();
    _grade += 1;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low!";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b) {
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return out;
}

void Bureaucrat::signForm(AForm &form){
    // if (!form.getIsSigned()){
        try {
            form.beSigned(*this);
            std::cout << this->_name << " signed: " << form.getName() << std::endl;
        } catch (std::exception& e) {
            std::cout << this->_name << " couldn't sign: " << form.getName();     
            std::cout << " because: " << e.what() << std::endl; 
        }
    // }
    // else
        // std::cout << "Form: " << form.getName() << " already signed!" << std::endl;
}

void Bureaucrat::executeForm(AForm const& form) const {
    try {
        form.execute(*this);
        std::cout << _name << " executed " << form.getName() << std::endl;
    } catch (std::exception& e) {
        std::cout << _name << " couldn't execute " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}
