#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
    std::cout << "=== ex00: Polymorphism with Animal ===\n\n";

    std::cout << "[CREAZIONE Animal]\n";
    const Animal* generic = new Animal();
    std::cout << "\n[CREAZIONE Dog]\n";
    const Animal* doggo   = new Dog();
    std::cout << "\n[CREAZIONE Cat]\n";
    const Animal* kitty   = new Cat();

    std::cout << "\n--- getType() ---\n";
    std::cout << "generic is a: " << generic->getType() << "\n";
    std::cout << "doggo   is a: " << doggo  ->getType() << "\n";
    std::cout << "kitty   is a: " << kitty  ->getType() << "\n";

    std::cout << "\n--- makeSound() ---\n";
    std::cout << "generic sound: "; generic->makeSound();
    std::cout << "doggo   sound: "; doggo  ->makeSound();
    std::cout << "kitty   sound: "; kitty  ->makeSound();

    std::cout << "\n--- delete Animal objects ---\n";
    delete generic; std::cout << "[deleted generic]\n";
    delete doggo;   std::cout << "[deleted doggo]\n";
    delete kitty;   std::cout << "[deleted kitty]\n";

    std::cout << "\n=== ex00: WrongAnimal (no virtual) ===\n\n";

    std::cout << "[CREAZIONE WrongAnimal]\n";
    const WrongAnimal* wrongBase   = new WrongAnimal();
    std::cout << "\n[CREAZIONE WrongCat]\n";
    const WrongAnimal* wrongKitty  = new WrongCat();

    std::cout << "\n--- getType() ---\n";
    std::cout << "wrongBase  is a: " << wrongBase ->getType() << "\n";
    std::cout << "wrongKitty is a: " << wrongKitty->getType() << "\n";

    std::cout << "\n--- makeSound() ---\n";
    std::cout << "wrongBase  sound: "; wrongBase ->makeSound();
    std::cout << "wrongKitty sound: "; wrongKitty->makeSound();
    std::cout << "   (NOT Dog::makeSound! WrongCat non-polimorfico)\n";

    std::cout << "\n--- delete WrongAnimal objects ---\n";
    delete wrongBase;  std::cout << "[deleted wrongBase]\n";
    delete wrongKitty; std::cout << "[deleted wrongKitty]\n";

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

