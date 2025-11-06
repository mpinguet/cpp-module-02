#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed(): value(0)
{
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy)
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

int Fixed::getRawBits() const
{
    return this->value;
}

Fixed &Fixed::operator=(const Fixed& other)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->value = other.getRawBits();
    return (*this);
}

void Fixed::setRawBits( int const raw )
{
    this->value = raw;
}
Fixed::Fixed(const int i)
{
	//std::cout << "Int constructor called" << std::endl;
	this->value = i << _fractionalBits;
}
Fixed::Fixed(const float i)
{
	// std::cout << "Float constructor called" << std::endl;
	this->value = roundf(i * (1 << _fractionalBits));
}
int Fixed::toInt() const
{
    return (this->value >> _fractionalBits);
}

float Fixed::toFloat() const
{
    return ((float)this->value / (float)(1 << _fractionalBits));
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a.toFloat() <= b.toFloat())
        return a;
    return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a.toFloat() <= b.toFloat())
        return a;
    return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a.toFloat() >= b.toFloat())
        return a;
    return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a.toFloat() >= b.toFloat())
        return a;
    return b;
}

bool Fixed::operator>(Fixed const &rhs) const
{
    return (this->value > rhs.value);
}

bool Fixed::operator<(Fixed const &rhs) const
{
    return (this->value < rhs.value);
}

bool Fixed::operator!=(Fixed const &rhs) const
{
    return (this->value != rhs.value);
}

bool Fixed::operator==(Fixed const &rhs) const
{
    return (this->value == rhs.value);
}

bool Fixed::operator<=(Fixed const &rhs) const
{
    return (this->value <= rhs.value);
}

bool Fixed::operator>=(Fixed const &rhs) const
{
    return (this->value >= rhs.value);
}

Fixed Fixed::operator+(Fixed const &rhs) const
{
    return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(Fixed const &rhs) const
{
    return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(Fixed const &rhs) const
{
    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(Fixed const &rhs) const
{
    return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed& Fixed::operator++()
{
    this->value = this->getRawBits() + 1;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp;
    tmp = *this;
    this->value += 1;
    return tmp;
}

Fixed& Fixed::operator--()
{
    this->value = this->getRawBits() - 1;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp;
    tmp = *this;
    this->value -= 1;
    return tmp;
}

std::ostream & operator<<(std::ostream & os, Fixed const & f)
{
    os << f.toFloat();
    return os;
}
