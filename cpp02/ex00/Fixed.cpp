#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() :
raw(0)
{
	std::cout << "\e[32mDefault constructor\e[m" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "\e[31mDestructor\e[m" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "\e[33mCopy constructor\e[m" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "\e[36mCopy assignment\e[m" << std::endl;
	raw = other.raw;
	return (*this);
}

int Fixed::getRawBits() const
{
	std::cout << "\e[30;1m" << __func__ << "\e[m" << std::endl;
	return (raw);
}

void Fixed::setRawBits(const int raw)
{
	std::cout << "\e[30;1m" << __func__  << "\e[m" << std::endl;
	this->raw = raw;
}
