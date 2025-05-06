#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
private:
    std::string ideas[100]; // static Array[100]

public:
    Brain();
    Brain(const Brain& other);// Copy constructor
    Brain& operator=(const Brain& other); // Copy assignment operator -> deep copy
    ~Brain();
    
    void setIdea(int index, const std::string& idea);
    std::string getIdea(int index) const;
};

#endif
