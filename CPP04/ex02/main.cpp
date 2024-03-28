#include "AAnimal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#define N 4

static void displayTitle(std::string t1, int nb, std::string t2) {
	if (nb != 0)
		std::cout << CYAN << "********** " << t1 << nb << t2 << " :" RESET << std::endl;
	else
		std::cout << CYAN << "********** " << t1 << RESET << std::endl;
}

void printCatIdeas(const Cat& cat) {
    for (int i = 0; i < N; i++)
        std::cout << cat.getIdea(i) << std::endl;
    std::cout << std::endl << std::endl;
}

void printDogIdeas(const Dog& dog) {
    for (int i = 0; i < N; i++)
            std::cout << dog.getIdea(i) << std::endl;
    std::cout << std::endl << std::endl;
}

int main()
{
	// displayTitle("PURE ANIMAL",0,"");
	// AAnimal* animal = new AAnimal();
	// delete animal;
	// std::cout << std::endl;

	displayTitle("Creation of ", N, " animals");
	AAnimal *animals[N];

	for (int i = 0; i < N; i++) 
	{
		if (i % 2 == 0)
		animals[i] = new Cat();
		else
		animals[i] = new Dog();
		std::cout << std::endl;
	}

	displayTitle("Make sound of the ", N, " animals");
	for (int i = 0; i < N; i++) {
		std::cout << animals[i]->getType() << " = ";
		animals[i]->makeSound();
	}
	std::cout << std::endl;

	displayTitle("Destruction of the ", N, " animals");
	for (int i = 0; i < N; i++) {
		delete animals[i];
		std::cout << std::endl;
	}
	std::cout << std::endl;
	
	displayTitle("COPY TESTS",0,"");
	Dog dog1;
	std::cout << "Dog1 idea 0: " << dog1.getIdea(0) << std::endl;
	std::cout << std::endl;
	dog1.setIdea(0, "Fluctuat nec megitur");
	printDogIdeas(dog1);

	displayTitle("Creating dog2. dog 2 is a copy of dog1",0,"");
	Dog dog2(dog1);
	printDogIdeas(dog2);
	displayTitle("Modifying dog2 ideas",0,"");
	dog2.setIdea(0, "Alea jacta est");
	dog2.setIdea(1, "Veni, vidi, vici");
	printDogIdeas(dog2);

	displayTitle("dog2 to is now assigned dog1 with operator=",0,"");
	dog2 = dog1;
	printDogIdeas(dog2);
	dog2.setIdea(0, "Tu quoque mi fili");
	std::cout << "dog2 = " << std::endl;
	printDogIdeas(dog2);
	std::cout << "dog2 = " << std::endl;
	printDogIdeas(dog1);
	
	displayTitle("Creating 2 Cat. Cat2 is a copy of cat1",0,"");
	Cat *cat1 =  new Cat();
	std::cout << "cat1 ideas = " << std::endl;
	printCatIdeas(*cat1);
	Cat *cat2 =  new Cat(*cat1);
	std::cout << "cat2 ideas = " << std::endl;
	printCatIdeas(*cat2);

	displayTitle("Modifying 2 first ideas of cat1",0,"");
	std::cout << "cat1 ideas = " << std::endl;
	cat1->setIdea(0, "In vino veritas");
	cat1->setIdea(1, "Festina lente");
	printCatIdeas(*cat1);
	std::cout << "cat2 ideas = " << std::endl;
	printCatIdeas(*cat2);
	
	displayTitle("Modifying 2 first ideas of cat2",0,"");
	std::cout << "cat1 ideas = " << std::endl;
	cat2->setIdea(0, "Memento mori");
	cat2->setIdea(1, "Carpe diem");
	printCatIdeas(*cat1);
	std::cout << "cat2 ideas = " << std::endl;
	printCatIdeas(*cat2);
	delete cat1;
	delete cat2;

	displayTitle("return",0,"");
}