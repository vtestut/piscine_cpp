#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

static void display_title(std::string title) {
	std::cout << CYAN << "--- " << title << " ---\n" << RESET;
}

void wrongAnimal(void) 
{
	const WrongAnimal* wrongCat = new WrongCat();
	const WrongAnimal* wrongAnimal = new WrongAnimal();

	std::cout << wrongCat->getType() << "\t: ";
	wrongCat->makeSound();
	std::cout << wrongAnimal->getType() << "\t: ";
	wrongAnimal->makeSound();

	delete wrongAnimal;
	delete wrongCat;
}

void rightAnimal(void) 
{
	const Animal* cat = new Cat();
	const Animal* dog = new Dog();
	const Animal* animal = new Animal();

	std::cout << cat->getType() << "\t: ";
	cat->makeSound();
	std::cout << dog->getType() << "\t: ";
	dog->makeSound();
	std::cout << animal->getType() << "\t: ";
	animal->makeSound();

	delete animal;
	delete cat;
	delete dog;
}

int main(void) 
{
	display_title("RIGHT ANIMAL");
	rightAnimal();
	std::cout << std::endl;
	display_title("WRONG ANIMAL");
	wrongAnimal();
	return (0);
}
