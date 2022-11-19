#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Animal* animals[6];
	for (int i = 0; i < 3; ++i)
		animals[i] = new Cat();	
	for (int i = 3; i < 6; ++i)
		animals[i] = new Dog();
	for (int i = 0; i < 6; ++i)
		delete animals[i];

	Cat cat;
	cat.getBrain().getIdeas()[13] = "Milk is white";
	Cat copyCat(cat);
	cat.getBrain().getIdeas()[13] = "Cats are fluffy";
	std::cout << copyCat.getBrain().getIdeas()[13] << std::endl;
	Cat otherCat;
	otherCat = cat;
	cat.getBrain().getIdeas()[13] = "Mice are tasty";
	std::cout << otherCat.getBrain().getIdeas()[13] << std::endl;
}
