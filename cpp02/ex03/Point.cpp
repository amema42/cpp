#include "Point.hpp"

// default ctor: init (0,0)
Point::Point( void ) : _x(0), _y(0) {}

// Param ctor: init (x,y)
Point::Point( float const x, float const y )
    : _x(x), _y(y) {}

// Copy of ctor
Point::Point( Point const & other )
    : _x(other._x), _y(other._y) {}

// Copy assign: -> no-op
Point & Point::operator=( Point const & ) {
    return *this;
}

// Dtor called
Point::~Point( void ) {}

Fixed Point::getX( void ) const { return _x; }
Fixed Point::getY( void ) const { return _y; }
