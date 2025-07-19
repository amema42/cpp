#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

//Form::Form(){}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false),_gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute){
    if (gradeToSign < 1 || gradeToExecute < 1 ){
        throw GradeTooHighException();
    }
    if (gradeToSign > 150 || gradeToExecute > 150 ){
        throw GradeTooLowException();
    }
}

Form::Form(const Form& other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute){ 
}

Form& Form::operator=(const Form& other){
    if (this != &other){
        this->_isSigned = other._isSigned;
    }
    return *this;

    // _name, _gradeToSign and _gradeToExecute are 'const' and cannot be copied
}

Form::~Form(){}

void    Form::beSigned(const Bureaucrat& b){
    if (b.getGrade()  <= _gradeToSign)
        _isSigned = true;
    else
        throw GradeTooLowException();
}

const std::string& Form::getName() const{
    return this->_name;
}
bool Form::getIsSigned() const{
    return this->_isSigned;
}
int Form::getGradeToSign() const{
    return this->_gradeToSign;
}
int Form::getGradeToExecute() const{
    return this->_gradeToExecute;
}

std::ostream& operator<<(std::ostream& out, const Form& f){
    out << "Form: " << f.getName() << "\nIs " << f.getName() << " signed? " << "<< " << std::boolalpha << f.getIsSigned() << " >>" << " Why?\nBecause it requires Grade to Sign: <=" << f.getGradeToSign() << " and requires Grade to Exe: <="<< f.getGradeToExecute() << "\n\n";
    return out;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade too low!";
}