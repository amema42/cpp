#include "Fixed.hpp"

// Default constructor
Fixed::Fixed( void ) : _rawBits(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Int constructor -> Trasla il valore per riservare bit ai decimali; Da intero a fixed-point
Fixed::Fixed( int const intVal ) {
    std::cout << "Int constructor called" << std::endl;
    _rawBits = intVal << _fractionalBits; 
}

// Float constructor; Scala, arrotonda e immagazzina; Da float a fixed-point
Fixed::Fixed( float const floatVal ) {
    std::cout << "Float constructor called" << std::endl;
    _rawBits = roundf(floatVal * (1 << _fractionalBits));
}

// Copy constructor
Fixed::Fixed( Fixed const & other ) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

// Copy assignment
Fixed & Fixed::operator=( Fixed const & other ) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        _rawBits = other.getRawBits();
    return *this;
}

// Destructor
Fixed::~Fixed( void ) {
    std::cout << "Destructor called" << std::endl;
}

// Raw bits accessors
int Fixed::getRawBits( void ) const {
    return _rawBits;
}

void Fixed::setRawBits( int const raw ) {
    _rawBits = raw;
}

// Conversion fixed → float; divide il valore raw per 2^_fractionalBits e lo restituisce come float
float Fixed::toFloat( void ) const {
    return _rawBits / static_cast<float>(1 << _fractionalBits);
}

// Conversion fixed → int; scorre a destra di _fractionalBits per scartare la parte frazionaria
int Fixed::toInt( void ) const {
    return _rawBits >> _fractionalBits;
}

// Overload operator<< per stampare la rappresentazione in float
std::ostream & operator<<( std::ostream & os, Fixed const & fp ) {
    os << fp.toFloat();
    return os;
}