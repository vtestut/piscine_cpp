#include "Dog.hpp"

/******************************************************************************/
/*								PUBLIC										  */
/******************************************************************************/

void Dog::makeSound() const {
  std::cout << "ouaf ouaf" << std::endl;
}

/******************************************************************************/
/*								ACCESSORS									  */
/******************************************************************************/

Brain * Dog::getBrain() const {
  return (this->brain);
}

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

Dog::Dog() : Animal() {
	this->_type = "Dog";
	this->brain = new Brain();
	std::cout << GREEN "Dog constructed" RESET << std::endl;
}

Dog::Dog(const Dog & obj) {
	*this = obj;
	std::cout << GREEN "Dog copied" RESET << std::endl;
}

Dog::~Dog() {
	delete this->brain;
	std::cout << RED "Dog destructed" RESET << std::endl;
}

/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/

Dog & Dog::operator=(const Dog & obj) {
	this->_type  = obj._type;
	this->brain = new Brain(*obj.brain);
	std::cout << GREEN "Dog assigned" RESET << std::endl;
	return (*this);
}






