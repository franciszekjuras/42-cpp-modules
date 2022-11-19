#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
public:
	Animal();
	virtual ~Animal();
	Animal(const Animal& other);
	Animal& operator=(const Animal& other);

	virtual void makeSound() const = 0;
	const std::string& getType() const;

protected:
	std::string type;
};

#endif
