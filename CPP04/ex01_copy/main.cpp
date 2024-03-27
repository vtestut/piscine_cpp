#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

// #define RESET "\033[0m"
// #define BOLDBLUE "\033[1m\033[34m"
#define NUM_ANIMALS 4

static void display_title(std::string title) {
	std::cout << CYAN << "--- " << title << " ---" RESET << std::endl;
}

int main()
{
	display_title("PURE ANIMAL");
	Animal* animal = new Animal();
	delete animal;
	std::cout << std::endl;

	display_title("DEFAULT CONSTRUCTORS");
	Animal* animals[NUM_ANIMALS] = {new Dog(), new Dog(), new Cat(), new Cat()};
	std::cout << std::endl;
	
	display_title("ANIMAL INFO");
	for (int i = 0; i < NUM_ANIMALS; ++i) {
		std::cout << "i: " << i << " type: " << animals[i]->getType() << " sound: ";
		animals[i]->makeSound();
	}
	std::cout << std::endl;
	
	display_title("DEEP COPY");
	Dog dog1;
	std::cout << "Dog1 idea 0: " << dog1.getIdea(0) << std::endl;
	dog1.setIdea(0, "Fluctuat nec megitur");
	std::cout << "Dog1 idea 0: " << dog1.getIdea(0) << std::endl;
	std::cout << std::endl;

	Dog dog2(dog1);
	std::cout << "Dog2 idea 0: " << dog2.getIdea(0) << std::endl;
	dog2.setIdea(0, "Alea jacta est");
	std::cout << "Dog2 idea 0: " << dog2.getIdea(0) << std::endl;
	std::cout << "Dog1 idea 0: " << dog1.getIdea(0) << std::endl;
	std::cout << std::endl;

	dog2 = dog1;
	std::cout << "Dog2 idea 0: " << dog2.getIdea(0) << std::endl;
	dog2.setIdea(0, "Tu quoque mi fili");
	std::cout << "Dog2 idea 0: " << dog2.getIdea(0) << std::endl;
	std::cout << "Dog1 idea 0: " << dog1.getIdea(0) << std::endl;
	std::cout << std::endl;
	
	display_title("DESTRUCTORS");
	for (int i = 0; i < NUM_ANIMALS; ++i)
		delete animals[i];
}