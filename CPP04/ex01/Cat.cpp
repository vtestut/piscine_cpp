#include "Cat.hpp"

/******************************************************************************/
/*								PUBLIC										  */
/******************************************************************************/

void Cat::makeSound() const {
	std::cout << "miaou miaou" << std::endl;
}

/******************************************************************************/
/*								ACCESSORS									  */
/******************************************************************************/

Brain * Cat::getBrain() const {
	return (this->brain);
}

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

Cat::Cat() : Animal() {
	this->_type = "Cat";
	this->brain = new Brain();
	std::cout << GREEN "Cat constructed" RESET << std::endl;
}

Cat::Cat(const Cat & obj) {
	*this = obj;
	std::cout << GREEN "Cat copied" RESET << std::endl;
}

Cat::~Cat() {
	delete this->brain;
	std::cout << RED "Cat destructed" RESET << std::endl;
}

/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/

Cat & Cat::operator=(const Cat & obj) {
	this->_type = obj._type;
	this->brain = new Brain(*obj.brain);
	std::cout << GREEN "Cat assigned" RESET << std::endl;
	return (*this);
}