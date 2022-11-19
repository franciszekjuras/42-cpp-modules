#ifndef DOG_HPP
#define DOG_HPP

#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
public:
	Dog();
	~Dog();
	Dog(const Dog& other);
	Dog& operator=(const Dog& other);

	void makeSound() const;
	const Brain& getBrain() const;
	Brain& getBrain();

private:
	Brain *brain;
};

#endif
