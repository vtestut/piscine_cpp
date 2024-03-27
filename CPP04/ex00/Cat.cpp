#include "Cat.hpp"

/******************************************************************************/
/*								PUBLIC										  */
/******************************************************************************/

void Cat::makeSound() const {
	std::cout << "miaou miaou" << std::endl;
}

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

Cat::Cat() {
	this->_type = "Cat";
	std::cout << GREEN "Cat constructed" RESET << std::endl;
}

Cat::Cat(const Cat & obj) {
	this->_type = obj._type;
	std::cout << GREEN "Cat copied" RESET << std::endl;
}

Cat::~Cat() {
	std::cout << RED "Cat destructed" RESET << std::endl;
}

/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/

Cat & Cat::operator=(const Cat & obj) {
	if (this != &obj)
		this->_type = obj._type;
	return (*this);
}
