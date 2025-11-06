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
    
    static Fixed &min(Fixed& a, Fixed& b);
    static const Fixed &min(const Fixed& a, const Fixed& b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);
    
    bool operator>(Fixed const &rhs) const;
    bool operator<(Fixed const &rhs) const;
    bool operator>=(Fixed const &rhs) const;
    bool operator<=(Fixed const &rhs) const;
    bool operator==(Fixed const &rhs) const;
    bool operator!=(Fixed const &rhs) const;

    Fixed operator+(Fixed const &rhs) const;
    Fixed operator-(Fixed const &rhs) const;
    Fixed operator*(Fixed const &rhs) const;
    Fixed operator/(Fixed const &rhs) const;

    Fixed& operator++();    // pré-incrément
    Fixed operator++(int);  // post-incrément
    Fixed& operator--();    // pré-décrément
    Fixed operator--(int);  // post-décrément
};

std::ostream &operator<<(std::ostream &os, Fixed const & value);
