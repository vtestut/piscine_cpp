#include "Animal.hpp"

/******************************************************************************/
/*								PUBLIC										  */
/******************************************************************************/

void Animal::makeSound() const {
	std::cout << "Animal noise" << std::endl;
}

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

Animal::Animal(void) : _type("Animal") {
	std::cout << GREEN "Animal constructed" RESET << std::endl;
}

Animal::Animal(const Animal & obj) : _type(obj._type) {
	std::cout << GREEN "Animal constructed" RESET << std::endl;
}

Animal::~Animal(void) {
	std::cout << RED "Animal destructed" RESET << std::endl;
}

/******************************************************************************/
/*								ACCESSORS									  */
/******************************************************************************/

std::string Animal::getType() const {
	return (this->_type);
}

/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/

Animal & Animal::operator=(const Animal & obj) {
	if (this != &obj)
		this->_type = obj._type;
	return (*this);
}
