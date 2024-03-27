#include "WrongAnimal.hpp"

/******************************************************************************/
/*								PUBLIC										  */
/******************************************************************************/

void WrongAnimal::makeSound() const {
	std::cout << "wrong animal noise" << std::endl;
}

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

WrongAnimal::WrongAnimal(void): _type("WrongAnimal") {
	std::cout << GREEN "WrongAnimal constructed" RESET << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & obj) : _type(obj._type) {
	std::cout << GREEN "WrongAnimal copied" RESET << std::endl;
}

WrongAnimal::~WrongAnimal(void) { 
	std::cout << RED "WrongAnimal destructed" RESET << std::endl;
}

/******************************************************************************/
/*							GETTERS & SETTERS								  */
/******************************************************************************/

std::string WrongAnimal::getType() const {
	return (this->_type);
}

/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/

WrongAnimal & WrongAnimal::operator=(const WrongAnimal & obj) {
	if (this != &obj)
		this->_type = obj._type;
	return (*this);
	std::cout << GREEN "WrongAnimal assigned" RESET << std::endl;
}
