#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int                 _rawBits;                    // Raw fixed-point integer value
    static const int    _fractionalBits = 8;         // Bit count for fractional part representation

public:
    // --- Orthodox Canonical Form ---
    Fixed( void );                                    // Default constructor: initializes fixed-point value
    Fixed( Fixed const & other );                     // Copy constructor: creates a new instance from another
    Fixed & operator=( Fixed const & other );         // Copy assignment: assigns state from another instance
    ~Fixed( void );                                   // Destructor: releases any allocated resources

    // Getters and setters for raw bits
    int getRawBits( void ) const;                     // Getter: returns the raw fixed-point value
    void setRawBits( int const raw );                 // Setter: updates the raw fixed-point value
};

#endif
