#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"


class Dog : public Animal
{
    public:
        Dog();
        virtual ~Dog();
        
        Dog(const Dog& other); // Copy constructor
        Dog& operator=(const Dog& other); // Copy assignment operator (=)
        
        void makeSound() const;
};

#endif
