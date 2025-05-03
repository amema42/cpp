#include "Fixed.hpp"

// Default constructor; sets _rawBits to 0 (Orthodox Canonical Form)
Fixed::Fixed( void ) : _rawBits(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Parameterized constructor converting int to fixed-point; shifts left by _fractionalBits (fixed-point scaling)
Fixed::Fixed( int const intVal ) {
    std::cout << "Int constructor called" << std::endl;
    _rawBits = intVal << _fractionalBits; 
}

// Parameterized constructor converting float to fixed-point; multiplies by 2^_fractionalBits and rounds (fixed-point conversion)
Fixed::Fixed( float const floatVal ) {
    std::cout << "Float constructor called" << std::endl;
    _rawBits = roundf(floatVal * (1 << _fractionalBits));
}

// Copy constructor; uses copy assignment for member-wise copy (Orthodox Canonical Form)
Fixed::Fixed( Fixed const & other ) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

// Copy assignment operator; checks self-assignment and copies _rawBits (Orthodox Canonical Form)
Fixed & Fixed::operator=( Fixed const & other ) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        _rawBits = other.getRawBits();
    return *this;
}

// Destructor; handles cleanup if needed (Orthodox Canonical Form)
Fixed::~Fixed( void ) {
    std::cout << "Destructor called" << std::endl;
}

// Access function; returns raw fixed-point value (const member function)
int Fixed::getRawBits( void ) const {
    return _rawBits;
}

// Mutator; sets raw fixed-point value
void Fixed::setRawBits( int const raw ) {
    _rawBits = raw;
}

// Conversion method; returns float value by dividing _rawBits by 2^_fractionalBits (fixed-point conversion)
float Fixed::toFloat( void ) const {
    return _rawBits / static_cast<float>(1 << _fractionalBits);
}

// Conversion method; returns int value by right-shifting _rawBits (truncates fractional part)
int Fixed::toInt( void ) const {
    return _rawBits >> _fractionalBits;
}

// Stream insertion operator overload; outputs the float conversion of fixed-point value (ad-hoc polymorphism)
std::ostream & operator<<( std::ostream & os, Fixed const & fp ) {
    os << fp.toFloat();
    return os;
}