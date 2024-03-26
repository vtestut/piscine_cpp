#include "AAnimal.hpp"

/******************************************************************************/
/*								ACCESSORS									  */
/******************************************************************************/

std::string AAnimal::getType() const { 
	return (this->_type);
}

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

AAnimal::AAnimal() : _type("AAnimal") {
	std::cout << GREEN "AAnimal constructed" RESET << std::endl;
}

AAnimal::AAnimal(const AAnimal & obj) : _type(obj._type) {
	std::cout << GREEN "AAnimal copied" RESET << std::endl;
}

AAnimal::~AAnimal() {
	std::cout << RED "AAnimal destructed" RESET << std::endl;
}

/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/

AAnimal & AAnimal::operator=(const AAnimal & obj) {
	if (this != &obj)
		this->_type = obj._type;
	std::cout << GREEN "AAnimal assigned" RESET << std::endl;
	return (*this);
}
