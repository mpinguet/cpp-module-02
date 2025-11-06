#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int value;
    static const int    _fractionalBits;
public:
    Fixed();
    Fixed(const Fixed&);
    Fixed &operator=(const Fixed&);
    Fixed(const int);
    Fixed(const float);
    ~Fixed();
    void setRawBits( int const raw );
    int getRawBits() const;
    int toInt() const;
    float toFloat() const;
};

std::ostream &operator<<(std::ostream &os, Fixed const & value);
