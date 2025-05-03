#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>  // roundf

class Fixed {
private:
    int                 _rawBits;
    static const int    _fractionalBits = 8;

public:
    // --- Orthodox Canonical Form ---
    Fixed( void );                        // default ctor
    Fixed( Fixed const & other );         // copy ctor
    Fixed & operator=( Fixed const & other ); // copy assignment
    ~Fixed( void );                       // dtor

    // --- New constructors ---
    Fixed( int const intVal );            // converte intero → fixed-point :contentReference[oaicite:2]{index=2}:contentReference[oaicite:3]{index=3}
    Fixed( float const floatVal );        // converte float → fixed-point :contentReference[oaicite:4]{index=4}:contentReference[oaicite:5]{index=5}

    // --- Member functions ---
    int   getRawBits( void ) const;
    void  setRawBits( int const raw );
    float toFloat( void ) const;         // fixed → float :contentReference[oaicite:6]{index=6}:contentReference[oaicite:7]{index=7}
    int   toInt( void ) const;           // fixed → int   :contentReference[oaicite:8]{index=8}:contentReference[oaicite:9]{index=9}
};

// Overload dell’inserzione su stream
std::ostream & operator<<( std::ostream & os, Fixed const & fp );

#endif