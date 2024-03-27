#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

#define N 4

static void display_title(std::string t1, int nb, std::string t2) {
	if (nb != 0)
		std::cout << CYAN << "********** " << t1 << nb << t2 << " :" RESET << std::endl;
	else
		std::cout << CYAN << "********** " << t1 << RESET << std::endl;
}

void printCatIdeas(const Cat& cat) {
    for (int i = 0; i < NB_IDEAS; i++)
        std::cout << cat.getBrain()->getIdeas()[i] << std::endl;
    std::cout << std::endl << std::endl;
}

void printDogIdeas(const Dog& dog) {
    for (int i = 0; i < NB_IDEAS; i++)
            std::cout << dog.getBrain()->getIdeas()[i] << std::endl;
    std::cout << std::endl << std::endl;
}

int main()
{
Animal *a[N];

// std::cout << CYAN "********** Creation of " << N << " animals:" RESET << std::endl;
display_title("Creation of ", N, " Animals");
for (int i = 0; i < N; i++) 
{
	if (i % 2 == 0)
	a[i] = new Cat();
	else
	a[i] = new Dog();
	std::cout << std::endl;
}

std::cout << CYAN "********** Make sound of the " << N << " animals:" RESET << std::endl;
for (int i = 0; i < N; i++)
	a[i]->makeSound();
std::cout << std::endl;

std::cout << CYAN "********** Desctruction of the " << N << " animals:" RESET << std::endl;
for (int i = 0; i < N; i++)
	delete a[i];
std::cout << std::endl;

std::cout << CYAN "********** Creation Cat cat1:" RESET << std::endl;
Cat * cat1 = new Cat();
std::cout << "cat1\t= " << cat1->getType() << std::endl;
printCatIdeas(*cat1);

std::cout << CYAN "********** Creation Cat cat2, a copy of cat1 with copy constructor :" RESET << std::endl;
Cat *cat2;
cat2 = new Cat(*cat1);
std::cout << "cat2\t= " << cat2->getType() << std::endl;
printCatIdeas(*cat2);

std::cout << CYAN "********** Modifying the two first ideas of cat1:" RESET << std::endl;
cat1->getBrain()->getIdeas()[0] = "Mens sana in corpore sano.";
cat1->getBrain()->getIdeas()[1] = "Alea Jacta Est.";
std::cout << "cat1 ideas =\n";
printCatIdeas(*cat1);
std::cout << "cat2 ideas =\n";
printCatIdeas(*cat2);

std::cout << CYAN "********** Modifying the two first idea of cat2:" RESET << std::endl;
cat2->getBrain()->getIdeas()[0] = "Mememto Mori";
cat2->getBrain()->getIdeas()[1] = "Carpe Diem";
std::cout << "cat1 ideas =\n";
printCatIdeas(*cat1);
std::cout << "cat2 ideas =\n";
printCatIdeas(*cat2);

// std::cout << CYAN "********** Desctruction of cat1 and cat2:" RESET << std::endl;
display_title("Destruction of cat1 and cat2", 0, "");
delete cat1;
delete cat2;
std::cout << std::endl;

std::cout << CYAN "********** Creation of Dog dog1:" RESET << std::endl;
Dog dog1;
std::cout << "dog1\t= " << dog1.getType() << std::endl;
printDogIdeas(dog1);

std::cout << CYAN "********** Creation Dog dog2, a copy of Dog1 with assigment constructor" RESET << std::endl;
Dog dog2 = dog1;
std::cout << "dog2\t= " << dog2.getType() << std::endl;
printDogIdeas(dog2);

std::cout << CYAN "********** Modifying of the two first ideas of dog1:" RESET << std::endl;
dog1.getBrain()->getIdeas()[0] = "In Vino Veritas";
dog1.getBrain()->getIdeas()[1] = "Festina Lente";
std::cout << "dog1 ideas =\n";
printDogIdeas(dog1);
std::cout << "dog2 ideas =\n";
printDogIdeas(dog2);

std::cout << CYAN "********** Modifying of the two first ideas of dog2:" RESET << std::endl;
dog2.getBrain()->getIdeas()[0] = "Veni, Vidi, Vici";
dog2.getBrain()->getIdeas()[1] = "Sic Parvis Magna";
std::cout << "dog1 ideas =\n";
printDogIdeas(dog1);
std::cout << "dog2 ideas=\n";
printDogIdeas(dog2);

std::cout << CYAN "********** Creation Animal a1:" RESET << std::endl;
Animal * const a1 = new Animal();
std::cout << "a1 = " << a1 << std::endl;
std::cout << "a1 = " << a1->getType() << std::endl << std::endl;

std::cout << CYAN "********** Creation Animal at2 - deep copy of a1:" RESET << std::endl;
Animal *a2;
a2 = new Animal(*a1);
std::cout << "a2 = " << a2 << std::endl;
std::cout << "a2 = " << a2->getType() << std::endl << std::endl;

std::cout << CYAN "********** Modifying the type of a1:" RESET << std::endl;
a1->setType("newType");
std::cout << "a1 type = " << a1->getType() << std::endl;
std::cout << "a2 type = " << a2->getType() << std::endl << std::endl;

std::cout << CYAN "********** Modifying the type of a2:" RESET << std::endl;
a2->setType("anotherType");
std::cout << "a1 type = " << a1->getType() << std::endl;
std::cout << "a2 type = " << a2->getType() << std::endl << std::endl;

std::cout << CYAN "********** Desctruction a1 and a2:" RESET << std::endl;
delete a1;
delete a2;
std::cout << std::endl;

std::cout << CYAN "********** return:" RESET << std::endl;
return 0;
}
