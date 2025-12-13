#include "Point.hpp"
#include "Fixed.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point( const Point& other ) : _x(other.getX()), _y(other.getY()) {}

Point::Point( const float x, const float y ) : _x(Fixed(x)), _y(Fixed(y)) {}

Point::~Point() {}

Point& Point::operator=( const Point& other )
{
    (void)other;
    return (*this);
}

const Fixed Point::getX( void ) const { return (_x); }

const Fixed Point::getY( void ) const { return (_y); }
