#include "Dog.hpp"

/******************************************************************************/
/*								PUBLIC										  */
/******************************************************************************/

void Dog::makeSound() const {
	std::cout << "ouaf ouaf" << std::endl;
}

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

Dog::Dog(void) {
	this->_type = "Dog";
	std::cout << GREEN "Dog constructed" RESET << std::endl;
}

Dog::Dog(const Dog & obj) {
	this->_type = obj._type;
	std::cout << GREEN "Dog copied" RESET << std::endl;
}

Dog::~Dog(void) {
	std::cout << RED "Dog destructed" RESET << std::endl;
}

/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/

Dog & Dog::operator=(const Dog & obj) {
	if (this != &obj)
		this->_type = obj._type;
	return (*this);
}
