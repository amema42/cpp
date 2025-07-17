#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>


class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        virtual ~Animal() = 0; // PURE "virtual Destructor": makes the Animal class abstract and non-instantiable

        Animal(const Animal& other); // Copy constructor
        Animal& operator=(const Animal& other); // Copy assignment operator

    // access the type attribute in read-only mode (const -> "read-only"; cannot modify)
        std::string getType() const;
        virtual void makeSound() const = 0;
};

#endif