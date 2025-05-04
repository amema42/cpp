#include "Fixed.hpp"

// Default constructor: Initializes _rawBits to "0" (1)
Fixed::Fixed( void ) : _rawBits(0) {
    std::cout << "Default constructor called" << std::endl;
}

// converts: int to fixed-point by shifting left "<<"" _fractionalBits (2)
Fixed::Fixed( int const intVal ) {
    std::cout << "Int constructor called" << std::endl;
    _rawBits = intVal << _fractionalBits; 
}

// converts: float to fixed-point by multiplying by 2^_fractionalBits and rounding
Fixed::Fixed( float const floatVal ) {
    std::cout << "Float constructor called" << std::endl;
    _rawBits = roundf(floatVal * (1 << _fractionalBits));
}

// copy constructor using assignment
Fixed::Fixed( Fixed const & other ) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

// Copy assignment; copies _rawBits.
Fixed & Fixed::operator=( Fixed const & other ) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        _rawBits = other.getRawBits();
    return *this;
}

Fixed::~Fixed( void ) {
    std::cout << "Destructor called" << std::endl;
}

// return (the raw fixed-point value)
int Fixed::getRawBits( void ) const {
    return _rawBits;
}

// sets the raw fixed-point value
void Fixed::setRawBits( int const raw ) {
    _rawBits = raw;
}

// converts -> fixed-point to float
float Fixed::toFloat( void ) const {
    return _rawBits / static_cast<float>(1 << _fractionalBits);
}

// converts -> fixed-point to int
int Fixed::toInt( void ) const {
    return _rawBits >> _fractionalBits;
}

// overloads the insertion operator to output: float value
std::ostream & operator<<( std::ostream & os, Fixed const & fp ) {
    os << fp.toFloat();
    return os;
}