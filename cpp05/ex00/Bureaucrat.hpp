#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat {
private:
    const std::string _name;
    int _grade;

public:
    // OCF
    Bureaucrat();
    Bureaucrat(std::string const& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    const std::string& getName() const;
    int getGrade() const;

    void setGradeUp(); //+1
    void setGradeDown(); //-1

    // Exception classes
    class GradeTooHighException : public std::exception {
    public:
        const char * what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char * what() const throw();
    };
};

// os operator (Output Stream)
std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif
