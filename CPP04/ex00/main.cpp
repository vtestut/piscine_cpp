#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

static void displayTitle(std::string title) {
	std::cout << CYAN << "********** " << title << RESET << std::endl;
}

void subjectTest(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	meta->makeSound();
	i->makeSound();
	j->makeSound();
	delete meta;
	delete j;
	delete i;
}

void wrongAnimal(void) 
{
	const WrongAnimal* wrongCat = new WrongCat();
	const WrongAnimal* wrongAnimal = new WrongAnimal();
	// const WrongCat * Cat2 = new WrongAnimal();
	// Cat2->makeSound();
	// delete Cat2;

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
	// const Dog * dog2 = new Animal();
	// dog2->makeSound();
	// delete dog2;

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
	displayTitle("subject test");
	subjectTest();
	std::cout << std::endl;
	displayTitle("good animal");
	rightAnimal();
	std::cout << std::endl;
	displayTitle("wrong animal");
	wrongAnimal();
	return (0);
}
