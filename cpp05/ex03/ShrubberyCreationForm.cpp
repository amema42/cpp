#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), _target(target){ }

// ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other){
//     _target = other._target;
// }

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target) {}


ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other){
    if (this != &other){
        AForm::operator=(other); // copy of: _isSigned && _executed 
        this->_target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){

}

// From AForm
void ShrubberyCreationForm::execute(Bureaucrat const& executor) const{
    if (!getIsSigned()) // if (false)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();
    
    std::ofstream file((_target + "_shrubbery").c_str());
    if (!file.is_open())
        throw std::runtime_error("Failed to open output file.");
    
    file << "                     .o00o\n";
    file << "                   o000000oo\n";
    file << "                  00000000000o\n";
    file << "                 00000000000000\n";
    file << "              oooooo  00000000  o88o\n";
    file << "           ooOOOOOOOoo  ```''  888888\n";
    file << "         OOOOOOOOOOOO'.qQQQQq. `8888'\n";
    file << "        oOOOOOOOOOO'.QQQQQQQQQQ/.88'\n";
    file << "        OOOOOOOOOO'.QQQQQQQQQQ/ /q\n";
    file << "         OOOOOOOOO QQQQQQQQQQ/ /QQ\n";
    file << "           OOOOOOOOO `QQQQQQ/ /QQ'\n";
    file << "             OO:F_P:O `QQQ/  /Q'\n";
    file << "                \\\\. \\ |  // |\n";
    file << "                d\\ \\\\\\|_////\n";
    file << "                qP| \\\\ _' `|Ob\n";
    file << "                   \\  / \\  \\Op\n";
    file << "                   |  | O| |\n";
    file << "           _       /\\. \\_/ /\\\n";
    file << "            `---__/|_\\\\   //|  __\n";
    file << "                  `-'  `-'`-'-'\n";

    file.close();
}