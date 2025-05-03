#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int                 _rawBits;
    static const int    _fractionalBits = 8;

public:
    // Orthodox Canonical Form
    Fixed( void );
    Fixed( Fixed const & other );
    Fixed & operator=( Fixed const & other );
    ~Fixed( void );

    // Constructors: implemented in ex01
    Fixed( int const intVal );
    Fixed( float const floatVal );

    // Conversions and accessors
    int   getRawBits( void ) const;
    void  setRawBits( int const raw );
    float toFloat( void ) const;
    int   toInt( void ) const;

    // operator Overloading: Comparisons
    bool operator>( Fixed const & other ) const;
    bool operator<( Fixed const & other ) const;
    bool operator>=( Fixed const & other ) const;
    bool operator<=( Fixed const & other ) const;
    bool operator==( Fixed const & other ) const;
    bool operator!=( Fixed const & other ) const;

    // operator: Overloading: Arithmetic Operations
    Fixed operator+( Fixed const & other ) const;
    Fixed operator-( Fixed const & other ) const;
    Fixed operator*( Fixed const & other ) const;
    Fixed operator/( Fixed const & other ) const;

    // Operator "Overloading": +/- operators
    Fixed & operator++();       // ++i op
    Fixed   operator++( int );  // i++ op
    Fixed & operator--();       // --i op
    Fixed   operator--( int );  // i-- op

    // Static min/max func
    static Fixed &       min( Fixed & a, Fixed & b );
    static Fixed const & min( Fixed const & a, Fixed const & b );
    static Fixed &       max( Fixed & a, Fixed & b );
    static Fixed const & max( Fixed const & a, Fixed const & b );
};

// Stream insertion operator: ex01
std::ostream & operator<<( std::ostream & os, Fixed const & fp );

#endif
