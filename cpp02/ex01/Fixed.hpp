#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>  // roundf

class Fixed {
private:
    int                 _rawBits;
    static const int    _fractionalBits = 8; // Fixed-point fractional precision

public:
    // --- Orthodox Canonical Form ---
    Fixed( void );                        // Default constructor (RAII, resource acquisition)
    Fixed( Fixed const & other );         // Copy constructor (deep copy for fixed-point representation)
    Fixed & operator=( Fixed const & other ); // Copy assignment operator (ensures proper resource copying)
    ~Fixed( void );                       // Destructor (cleans up resources if needed)

    // --- New constructors ---
    Fixed( int const intVal );            // Converts integer to fixed-point (integral conversion)
    Fixed( float const floatVal );        // Converts float to fixed-point (floating-point conversion)

    // --- Member functions ---
    int   getRawBits( void ) const;       // Retrieves raw fixed-point data (const correctness)
    void  setRawBits( int const raw );    // Sets raw fixed-point data (direct memory management)
    float toFloat( void ) const;          // Converts fixed-point to float (precision conversion)
    int   toInt( void ) const;            // Converts fixed-point to int (truncation conversion)
};

// Stream insertion operator overload for direct output (operator overloading, ad-hoc polymorphism)
std::ostream & operator<<( std::ostream & os, Fixed const & fp );

#endif