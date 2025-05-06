#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "- Object creation -\n";

    const Animal* generic = new Animal();
    std::cout << "-\n";

    const Animal* doggo   = new Dog();
    const Animal* kitty   = new Cat();

    std::cout << "\n- Type verification with getType() -\n";
    std::cout << "generic is a:  " << generic->getType() << std::endl;
    std::cout << "doggo is a:    " << doggo->getType()   << std::endl;
    std::cout << "kitty is a:    " << kitty->getType()   << std::endl;

    std::cout << "\n- Call to makeSound() -\n";
    std::cout << "generic sound: ";
    generic->makeSound();
    std::cout << "doggo sound:   ";
    doggo->makeSound();
    std::cout << "kitty sound:   ";
    kitty->makeSound();

    std::cout << "\n ~ ~ ~ \n";
    
    delete generic;
    delete doggo;
    delete kitty;
    //delete generic;
    
    std::cout << "\n- WrongAnimal -\n";
    
    const WrongAnimal* wrongBase = new WrongAnimal();
    const WrongAnimal* wrongKitty = new WrongCat();
    
    std::cout << "wrongKitty is a: " << wrongKitty->getType() << std::endl;
    std::cout << "wrongBase sound:   "; wrongBase->makeSound();
    std::cout << "wrongKitty sound:  "; wrongKitty->makeSound(); // NOT what you expect
    
    delete wrongBase;
    delete wrongKitty;

    return 0;
}



// int main()
// {
//     const Animal* j = new Dog();
//     const Animal* i = new Cat();
//     delete j; //should not create a leak
//     delete i;

//     return 0;
// }

