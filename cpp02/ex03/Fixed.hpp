#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
    int                 _rawBits;
    static const int    _fractionalBits = 8;

public:
    // Orthodox Canonical Form (1)(2)(3)(4)/ "methods"
    Fixed(void);
    Fixed(Fixed const &other);
    Fixed &operator=(Fixed const &other);
    ~Fixed(void);

    // Conversion constructors
    Fixed(int const intVal);
    Fixed(float const floatVal);

    // getters & converters
    int   getRawBits(void) const;
    void  setRawBits(int const raw);
    float toFloat(void) const;
    int   toInt(void) const;

    // comparisons
    bool operator>(Fixed const &other) const;
    bool operator<(Fixed const &other) const;
    bool operator>=(Fixed const &other) const;
    bool operator<=(Fixed const &other) const;
    bool operator==(Fixed const &other) const;
    bool operator!=(Fixed const &other) const;

    // arithmetic operators
    Fixed operator+(Fixed const &other) const;
    Fixed operator-(Fixed const &other) const;
    Fixed operator*(Fixed const &other) const;
    Fixed operator/(Fixed const &other) const;

    // increment/decrement operators
    Fixed &operator++();      // pre-increment
    Fixed  operator++(int);    // post-increment
    Fixed &operator--();      // pre-decrement
    Fixed  operator--(int);    // post-decrement

    // min/max utilities
    static Fixed &min(Fixed &a, Fixed &b);
    static Fixed const &min(Fixed const &a, Fixed const &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static Fixed const &max(Fixed const &a, Fixed const &b);
};

// Stream "insertion"
std::ostream &operator<<(std::ostream &os, Fixed const &fp);

#endif
