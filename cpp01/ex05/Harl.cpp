#include "Harl.hpp"

Harl::Harl( void ) {}
Harl::~Harl( void ) {}

void Harl::debug( void ) {
    std::cout << "[ DEBUG ]\n"
              << "I love having extra bacon for my "
                 "7XL-double-cheese-triple-pickle-special-ketchup burger. "
                 "I really do!\n"
              << std::endl;
}

void Harl::info( void ) {
    std::cout << "[ INFO ]\n"
              << "I cannot believe adding extra bacon costs more money. "
                 "You didn’t put enough bacon in my burger! If you did, I "
                 "wouldn’t be asking for more!\n"
              << std::endl;
}

void Harl::warning( void ) {
    std::cout << "[ WARNING ]\n"
              << "I think I deserve to have some extra bacon for free. "
                 "I’ve been coming for years, whereas you started working "
                 "here just last month.\n"
              << std::endl;
}

void Harl::error( void ) {
    std::cout << "[ ERROR ]\n"
              << "This is unacceptable! I want to speak to the manager now.\n"
              << std::endl;
}

void Harl::complain( std::string level ) {
    // "level" names array
    static const std::string levels[] = {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
    };

    // parallel "array" of member function pointers
    typedef void (Harl::*HarlMemFn)(void);
    static const HarlMemFn funcs[] = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    // search for matching level; call associated function
    for (int i = 0; i < 4; ++i) {
        if (level == levels[i]) {
            (this->*funcs[i])();
            return;
        }
    }
    // If: level not found? no action
}

/*
levels and funcs are parallel arrays;
(this->*funcs[i])() calls the corresponding member function.
*/