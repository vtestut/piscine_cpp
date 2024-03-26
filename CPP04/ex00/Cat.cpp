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

Cat::Cat(void) {
	this->_type = "Cat";
	std::cout << CYAN "Cat constructed" RESET << std::endl;
}

Cat::Cat(const Cat& obj) {
	this->_type = obj._type;
	std::cout << CYAN "Cat constructed" RESET << std::endl;
}

Cat::~Cat(void) { std::cout << RED "Cat destructed" RESET << std::endl; }

/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/

Cat & Cat::operator=(const Cat & obj) {
	if (this != &obj)
		this->_type = obj._type;
	return (*this);
}