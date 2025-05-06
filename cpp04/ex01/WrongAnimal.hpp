#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>


class WrongAnimal
{
    protected:
        std::string type;
    public:
        WrongAnimal();
        ~WrongAnimal(); // not virtual!
        WrongAnimal(const WrongAnimal& other);
        WrongAnimal& operator=(const WrongAnimal& other);

    // access the type attribute in read-only mode (const -> "read-only"; cannot modify)
        std::string getType() const;
        void makeSound() const; // not virtual!
};

#endif