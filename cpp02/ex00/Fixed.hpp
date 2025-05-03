#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int                 _rawBits;                    // valore raw del numero fisso -> integer
    static const int    _fractionalBits = 8;         // numero di bit per la parte frazionaria

public:
    // --- Orthodox Canonical Form ---
    Fixed( void );                                    // default constructor
    Fixed( Fixed const & other );                     // copy constructor
    Fixed & operator=( Fixed const & other );         // copy assignment
    ~Fixed( void );                                   // destructor

    // getter e setter per: raw bits
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};

#endif
