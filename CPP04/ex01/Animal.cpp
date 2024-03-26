#include "Animal.hpp"

/******************************************************************************/
/*								PUBLIC FUNCTIONS							  */
/******************************************************************************/

void Animal::makeSound() const {
	std::cout << "???";
}

std::string Animal::getType() const {
	return this->type;
}

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

Animal::Animal() : type("Animal") { 
	std::cout << "Animal constructed.\n"; 
}

Animal::Animal(const Animal& animal) : type(animal.type) { 
	std::cout << "Animal copied.\n"; 
}

Animal::~Animal() { 
	std::cout << "Animal destructed.\n"; 
}

/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/

Animal& Animal::operator=(Animal const& animal) {
	if (this != &animal)
		this->type = animal.type;
	std::cout << "Animal assigned.\n";
	return *this;
}
