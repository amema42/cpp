#include "Harl.hpp"
#include <iostream>

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
    // Array di stringhe con i nomi dei livelli
    static const std::string levels[] = {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
    };

    // Array parallelo di puntatori a membro
    typedef void (Harl::*HarlMemFn)(void);
    static const HarlMemFn funcs[] = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    // Cerco il livello e, se trovato, chiamo il membro corrispondente
    for (int i = 0; i < 4; ++i) {
        if (level == levels[i]) {
            (this->*funcs[i])();
            return;
        }
    }
    // Se il livello non è uno dei quattro -> do nothing
}

/*
levels[] & levels[] sono paralleli; a levels[i] corrisponde funcs[i]
(this->*funcs[i])(); -> chiamo il membro corrispondente nel loop
*/