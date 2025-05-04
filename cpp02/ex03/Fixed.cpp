#include "Fixed.hpp"

// Canonical methods
Fixed::Fixed( void ) : _rawBits(0)                  { std::cout << "Default constructor called\n"; }
Fixed::Fixed( Fixed const & other )                 { std::cout << "Copy constructor called\n"; *this = other; }
Fixed & Fixed::operator=( Fixed const & other )     { std::cout << "Copy assignment operator called\n"; if (this != &other) _rawBits = other._rawBits; return *this; }
Fixed::~Fixed( void )                               { std::cout << "Destructor called\n"; }

// Conversion constructors 
Fixed::Fixed( int const intVal )                    { std::cout << "Int constructor called\n";   _rawBits = intVal << _fractionalBits; }
Fixed::Fixed( float const floatVal )                { std::cout << "Float constructor called\n"; _rawBits = roundf(floatVal * (1 << _fractionalBits)); }

// accessors and conversions
int   Fixed::getRawBits( void ) const               { return _rawBits; }
void  Fixed::setRawBits( int const raw )            { _rawBits = raw; }
float Fixed::toFloat( void ) const                  { return _rawBits / static_cast<float>(1 << _fractionalBits); }
int   Fixed::toInt( void ) const                    { return _rawBits >> _fractionalBits; }

// comparison operators
bool Fixed::operator>( Fixed const & o ) const      { return _rawBits >  o._rawBits; }
bool Fixed::operator<( Fixed const & o ) const      { return _rawBits <  o._rawBits; }
bool Fixed::operator>=( Fixed const & o ) const     { return _rawBits >= o._rawBits; }
bool Fixed::operator<=( Fixed const & o ) const     { return _rawBits <= o._rawBits; }
bool Fixed::operator==( Fixed const & o ) const     { return _rawBits == o._rawBits; }
bool Fixed::operator!=( Fixed const & o ) const     { return _rawBits != o._rawBits; }

// arithmetic operators
Fixed Fixed::operator+( Fixed const & o ) const     { Fixed r; r._rawBits = _rawBits + o._rawBits; return r; }
Fixed Fixed::operator-( Fixed const & o ) const     { Fixed r; r._rawBits = _rawBits - o._rawBits; return r; }
Fixed Fixed::operator*( Fixed const & o ) const     { Fixed r; long t = static_cast<long>(_rawBits) * o._rawBits; r._rawBits = static_cast<int>( t >> _fractionalBits ); return r; }
Fixed Fixed::operator/( Fixed const & o ) const     { Fixed r; long t = (static_cast<long>(_rawBits) << _fractionalBits); r._rawBits = static_cast<int>( t / o._rawBits ); return r; }

// -/+ operators
Fixed & Fixed::operator++()       { ++_rawBits; return *this; }
Fixed   Fixed::operator++( int )  { Fixed tmp(*this); ++_rawBits; return tmp; }
Fixed & Fixed::operator--()       { --_rawBits; return *this; }
Fixed   Fixed::operator--( int )  { Fixed tmp(*this); --_rawBits; return tmp; }

// static min/max functions
Fixed & Fixed::min( Fixed & a, Fixed & b )                   { return (a < b ? a : b); }
Fixed const & Fixed::min( Fixed const & a, Fixed const & b )   { return (a < b ? a : b); }
Fixed & Fixed::max( Fixed & a, Fixed & b )                   { return (a > b ? a : b); }
Fixed const & Fixed::max( Fixed const & a, Fixed const & b )   { return (a > b ? a : b); }

// stream insertion operator
std::ostream & operator<<( std::ostream & os, Fixed const & fp ) {
    os << fp.toFloat();
    return os;
}
