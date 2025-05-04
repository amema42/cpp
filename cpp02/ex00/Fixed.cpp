#include "Fixed.hpp"

// default constructor: initializes _rawBits to 0 
Fixed::Fixed( void ) : _rawBits(0) {
    std::cout << "Default constructor called" << std::endl;
}

// COPY CONSTRUCTOR: duplicates state -> copy assignment (Rule of Three)
Fixed::Fixed( Fixed const & other ) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed & Fixed::operator=( Fixed const & other ) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_rawBits = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed( void ) {
    std::cout << "Destructor called" << std::endl;
}

// getRawBits: returns current raw fixed-point value
int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_rawBits;
}

// setRawBits: updates raw fixed-point value directly
void Fixed::setRawBits( int const raw ) {
    this->_rawBits = raw;
}
