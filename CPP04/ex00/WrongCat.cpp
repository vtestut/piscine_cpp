#include "WrongCat.hpp"

/******************************************************************************/
/*								PUBLIC										  */
/******************************************************************************/

void WrongCat::makeSound() const {
	std::cout << "puke puke" << std::endl;
}

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

WrongCat::WrongCat(void) {
	this->_type = "WrongCat";
	std::cout << GREEN "WrongCat constructed" RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat & obj) {
	this->_type = obj._type;
	std::cout << GREEN "WrongCat copied" RESET << std::endl;
}

WrongCat::~WrongCat(void) {
	std::cout << RED "WrongCat destructed" RESET << std::endl;
}

/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/

WrongCat & WrongCat::operator=(const WrongCat & obj) {
	if (this != &obj)
		this->_type = obj._type;
	std::cout << GREEN "WrongCat assigned" RESET << std::endl;
	return (*this);
}
