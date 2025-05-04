#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>  // need 4 roundf

class Fixed {
private:
    int                 _rawBits;
    static const int    _fractionalBits = 8; // fractional precision -> 2^8 = 256/ Last 8 bits are fractional

public:
    // Canonical Form
    Fixed( void );                      // default constructor
    Fixed( Fixed const & other );       // copy constructor
    Fixed & operator=( Fixed const & other ); // copy assignment
    ~Fixed( void );                     // destructor

    // conversions
    Fixed( int const intVal );          // convert int to fixed-point
    Fixed( float const floatVal );      // convert float to fixed-point

    // "asccessors"
    int   getRawBits( void ) const;
    void  setRawBits( int const raw );
    float toFloat( void ) const;
    int   toInt( void ) const;
};

std::ostream & operator<<( std::ostream & os, Fixed const & fp );

#endif
