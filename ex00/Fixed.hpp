#pragma once

#include <iostream>

class Fixed
{
private:
    int value;
    static const int    _fractionalBits;
public:
    Fixed();
    Fixed(const Fixed&);
    ~Fixed();
    Fixed &operator=(const Fixed&);
    void setRawBits( int const raw );
    int getRawBits() const;
};