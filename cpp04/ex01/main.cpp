#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

#define ARRAY_SIZE 4

int main()
{
    std::cout << "- alloc an array of Animal* [array]\n";

    Animal* animals[ARRAY_SIZE];

    // first half: Dog
    for (int i = 0; i < ARRAY_SIZE / 2; ++i)
    {
        std::cout << "\n[CREATING DOG " << i << "]\n";
        animals[i] = new Dog();
    }

    // second half: Cat
    for (int i = ARRAY_SIZE / 2; i < ARRAY_SIZE; ++i)
    {
        std::cout << "\n[CREATING CAT " << i << "]\n";
        animals[i] = new Cat();
    }

    std::cout << "\n CREATING AND COPYing DOGS [deep copy test]\n";

    Dog* dog1 = new Dog(); // Original Dog
    dog1->setIdea(0, "Let me out!");             //set idea0
    dog1->setIdea(1, "Bark at the mailman!");      // set idea1

    Dog* dog2 = new Dog(*dog1); // Copy constructor → deep copy

    std::cout << "[CHECK] Dog1 idea 0: " << dog1->getIdea(0) << "\n";
    std::cout << "[CHECK] Dog2 idea 0: " << dog2->getIdea(0) << "\n";

    std::cout << "\n[MODIFICATION] Changing dog2 idea 0\n";
    dog2->setIdea(0, "Free palestine!");

    std::cout << "[CHECK] Dog1 idea 0 (after modifying Dog2): " << dog1->getIdea(0) << "\n";
    std::cout << "[CHECK] Dog2 idea 0: " << dog2->getIdea(0) << "\n";

    std::cout << "\n- DEL OF Dog1 and Dog2 -[delete]\n";
    delete dog1;
    delete dog2;

    std::cout << "\n- DEL of the ANIMALS ARRAY - [delete loop]\n";

    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        std::cout << "\n[DEL ANIMAL " << i << "]\n";
        delete animals[i];
    }

    std::cout << "all objects destroyed correctly. Daje! End.\n";
    return 0;
}


//---
// #include "Animal.hpp"
// #include "Dog.hpp"
// #include "Cat.hpp"
// #include "WrongAnimal.hpp"
// #include "WrongCat.hpp"

// int main()
// {
//     std::cout << "- Object creation -\n";

//     const Animal* generic = new Animal();
//     std::cout << "-\n";

//     const Animal* doggo   = new Dog();
//     const Animal* kitty   = new Cat();

//     std::cout << "\n- Type verification with getType() -\n";
//     std::cout << "generic is a:  " << generic->getType() << std::endl;
//     std::cout << "doggo is a:    " << doggo->getType()   << std::endl;
//     std::cout << "kitty is a:    " << kitty->getType()   << std::endl;

//     std::cout << "\n- Call to makeSound() -\n";
//     std::cout << "generic sound: ";
//     generic->makeSound();
//     std::cout << "doggo sound:   ";
//     doggo->makeSound();
//     std::cout << "kitty sound:   ";
//     kitty->makeSound();

//     std::cout << "\n ~ ~ ~ \n";
    
//     delete generic;
//     delete doggo;
//     delete kitty;
//     //delete generic;
    
//     std::cout << "\n- WrongAnimal -\n";
    
//     const WrongAnimal* wrongBase = new WrongAnimal();
//     const WrongAnimal* wrongKitty = new WrongCat();
    
//     std::cout << "wrongKitty is a: " << wrongKitty->getType() << std::endl;
//     std::cout << "wrongBase sound:   "; wrongBase->makeSound();
//     std::cout << "wrongKitty sound:  "; wrongKitty->makeSound(); // NOT what you expect
    
//     delete wrongBase;
//     delete wrongKitty;

//     return 0;
// }



// int main()
// {
//     const Animal* j = new Dog();
//     const Animal* i = new Cat();
//     delete j; //should not create a leak
//     delete i;

//     return 0;
// }

