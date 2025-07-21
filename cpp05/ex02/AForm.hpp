#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat;

class AForm{
private:
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;
    mutable bool _executed;

public:
    //AForm();
    AForm(const std::string& name, int gradeToSign, int gradeToExecute);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    ~AForm();

    const std::string& getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    bool getWasExecuted() const;

    void setWasExecuted(bool executed) const;


    void    beSigned(const Bureaucrat& b);

    virtual void execute(Bureaucrat const& executor) const = 0;

    class GradeTooHighException : public std::exception {
    public:
        const char * what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char * what() const throw();
    };

    class FormNotSignedException : public std::exception {
    public:
        const char * what() const throw();
    };

    class FormAlreadySignedException : public std::exception{
    public:
        const char * what() const throw();
    };

    class FormAlreadyExecuted : public std::exception {
    public:
        const char * what() const throw();
    };

};

std::ostream& operator<<(std::ostream& out, const AForm& f);


#endif