#include <iostream>
#include <stdint.h>
#include <sys/time.h>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate()
{
	struct timeval tm;
	gettimeofday(&tm, NULL);
	if (tm.tv_usec % 3 == 0)
		return (new A());
	else if (tm.tv_usec % 3 == 1)
		return (new B());
	else
		return (new C());
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;	
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	try {dynamic_cast<A&>(p); std::cout << "A" << std::endl;}
	catch (const std::exception& e) {}
	try {dynamic_cast<B&>(p); std::cout << "B" << std::endl;}
	catch (const std::exception& e) {}
	try {dynamic_cast<C&>(p); std::cout << "C" << std::endl;}
	catch (const std::exception& e) {}
}

int main()
{
	Base* p;
	for (int i = 0; i < 5; ++i)
	{
		p = generate();
		identify(p);
		identify(*p);
		std::cout << "---" << std::endl;
		delete p;
	}
}