#include "Fixed.hpp"

// Default constr
Fixed::Fixed( void ) : _rawBits(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Copy constr
Fixed::Fixed( Fixed const & other ) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;  // sfrutta operator=
}

// Copy assignment operator
Fixed & Fixed::operator=( Fixed const & other ) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_rawBits = other.getRawBits();
    }
    return *this;
}

// Destructor
Fixed::~Fixed( void ) {
    std::cout << "Destructor called" << std::endl;
}

// getRawBits
int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_rawBits;
}

// setRawBits
void Fixed::setRawBits( int const raw ) {
    this->_rawBits = raw;
}
