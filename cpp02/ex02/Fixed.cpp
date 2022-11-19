#include "Fixed.hpp"
#include <iostream>
#include <ostream>
#include <cmath>

Fixed::Fixed() :
raw(0)
{
	// std::cout << "\e[32mDefault constructor\e[m" << std::endl;
}

Fixed::Fixed(int value)
{
	// std::cout << "\e[32mInteger constructor\e[m" << std::endl;
	raw = value * (1 << point);
}

Fixed::Fixed(float value)
{
	// std::cout << "\e[32mFloat constructor\e[m" << std::endl;
	raw = static_cast<int>(roundf(value * (1 << point)));
}

Fixed::~Fixed()
{
	// std::cout << "\e[31mDestructor\e[m" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	// std::cout << "\e[33mCopy constructor\e[m" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	// std::cout << "\e[36mCopy assignment\e[m" << std::endl;
	raw = other.raw;
	return (*this);
}

int Fixed::getRawBits() const
{
	// std::cout << "\e[30;1m" << __func__ << "\e[m" << std::endl;
	return (raw);
}

void Fixed::setRawBits(const int raw)
{
	// std::cout << "\e[30;1m" << __func__  << "\e[m" << std::endl;
	this->raw = raw;
}

int Fixed::toInt() const
{
	return (raw / (1 << point));
}

float Fixed::toFloat() const
{
	return (static_cast<float>(raw) / (1 << point));
}

bool Fixed::operator<(const Fixed& other) const
{
	return (this->raw < other.raw);
}

bool Fixed::operator>(const Fixed& other) const
{
	return (this->raw > other.raw);
}

bool Fixed::operator<=(const Fixed& other) const
{
	return (this->raw <= other.raw);
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (this->raw >= other.raw);
}

bool Fixed::operator==(const Fixed& other) const
{
	return (this->raw == other.raw);
}

bool Fixed::operator!=(const Fixed& other) const
{
	return (this->raw != other.raw);
}

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed res;
	res.setRawBits(this->raw + other.raw);
	return (res);
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed res;
	res.setRawBits(this->raw - other.raw);
	return (res);
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed res;
	res.setRawBits(this->raw * other.raw / (1 << point));
	return (res);
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed res;
	res.setRawBits(this->raw * (1 << point) / other.raw);
	return (res);
}

Fixed& Fixed::operator++()
{
	++raw;
	return (*this);
}

Fixed& Fixed::operator--()
{
	--raw;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed res = *this;
	++*this;
	return (res);
}

Fixed Fixed::operator--(int)
{
	Fixed res = *this;
	--*this;
	return (res);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

std::ostream& operator<<(std::ostream &out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}
