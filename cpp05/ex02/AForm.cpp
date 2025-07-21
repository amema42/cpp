#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

// AForm::AForm(){}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false),_gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _executed(false){
    if (gradeToSign < 1 || gradeToExecute < 1 ){
        throw GradeTooHighException();
    }
    if (gradeToSign > 150 || gradeToExecute > 150 ){
        throw GradeTooLowException();
    }
}

AForm::AForm(const AForm& other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute){ 
}

AForm& AForm::operator=(const AForm& other){
    if (this != &other){
        this->_isSigned = other._isSigned;
    }
    return *this;

    // _name, _gradeToSign and _gradeToExecute are 'const' and cannot be copied
}

AForm::~AForm(){}

void    AForm::beSigned(const Bureaucrat& b){
    if (_isSigned)
        throw FormAlreadySignedException();
    if (b.getGrade()  <= _gradeToSign)
        _isSigned = true;
    else
        throw GradeTooLowException();
}

const std::string& AForm::getName() const{
    return this->_name;
}
bool AForm::getIsSigned() const{
    return this->_isSigned;
}
int AForm::getGradeToSign() const{
    return this->_gradeToSign;
}
int AForm::getGradeToExecute() const{
    return this->_gradeToExecute;
}

std::ostream& operator<<(std::ostream& out, const AForm& f){
    out << "Form: " << f.getName() << "\nIs " << f.getName() << " signed? " << "<< " << std::boolalpha << f.getIsSigned() << " >>" << " Why?\nBecause it requires Grade to Sign: <=" << f.getGradeToSign() << " and requires Grade to Exe: <="<< f.getGradeToExecute() << "\n\n";
    return out;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed!";
}

const char * AForm::FormAlreadyExecuted::what() const throw(){
    return "Form Already Executed!";
}

const char * AForm::FormAlreadySignedException::what() const throw(){
    return "Form Already Signed!";
}

bool AForm::getWasExecuted() const {
    return _executed;
}

void AForm::setWasExecuted(bool executed) const{
    _executed = executed;
}