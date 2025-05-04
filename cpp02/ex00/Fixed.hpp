#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int                 _rawBits;
    static const int    _fractionalBits = 8;         // frac "prcision" -> 2^8 = 256/ Last 8 bits are fractional

public:
    // Canonical (Orth) Form
    Fixed( void );
    Fixed( Fixed const & other );
    Fixed & operator=( Fixed const & other );
    ~Fixed( void );

    // raw val "access"
    int getRawBits( void ) const;                     // returns (raw value)
    void setRawBits( int const raw );                 // sets (raw value)
};

#endif

// Canonical Form: Fixed( void );
// (1)default Constructor
// (2)copy constructor
// (3)copy "assignment"
// (4) destructor