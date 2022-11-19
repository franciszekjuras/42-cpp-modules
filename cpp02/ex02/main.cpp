#include "Fixed.hpp"
#include <iostream>
#include <ios>
#include <bitset>

int main()
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << --a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;
	Fixed const c( Fixed( 1.25f ) / Fixed( 0.5f ) );
	std::cout << c << std::endl;
	Fixed const d( Fixed( 1.25f ) + Fixed( -0.5f ) );
	std::cout << d << std::endl;	
	Fixed const e( Fixed( 0.25f ) - Fixed( 0.5f ) );
	std::cout << e << std::endl;
}
