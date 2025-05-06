#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        virtual ~WrongCat();

        WrongCat(const WrongCat& other);
        WrongCat& operator=(const WrongCat& other); //tries to override, but won't work polymorphically talking
        
        void makeSound() const;
};

#endif