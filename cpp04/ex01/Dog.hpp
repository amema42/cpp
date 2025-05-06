#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"


class Dog : public Animal
{
    private:
        Brain* brain; // Pointer to { Brain } object
    public:
        Dog();
        virtual ~Dog();
        
        Dog(const Dog& other); // Copy constructor
        Dog& operator=(const Dog& other); // Copy assignment operator (=)
        
        void makeSound() const;

        void setIdea(int index, const std::string& idea);
        std::string getIdea(int index) const;
};

#endif
