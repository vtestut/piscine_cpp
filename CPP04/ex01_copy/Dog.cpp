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

std::string Dog::getIdea(int idx) const {
	if (this->brain == NULL)
		throw std::logic_error("Brain pointer is NULL");
	if (idx < 0 || idx >= NUM_IDEAS)
		throw std::out_of_range("ideas[idx] is out of range");
	return (this->brain->ideas[idx]);
}

void Dog::setIdea(int idx, std::string idea) {
	if (this->brain == NULL)
		throw std::logic_error("Brain pointer is NULL");
	if (idx < 0 || idx >= NUM_IDEAS)
		throw std::out_of_range("ideas[idx] is out of range");
	this->brain->ideas[idx] = idea;
}

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

Dog::Dog() {
	this->_type = "Dog";
	this->brain = new Brain();
	std::cout << GREEN "Dog constructed" RESET << std::endl;
}

Dog::Dog(const Dog & obj) {
	this->_type = obj._type;
	if (obj.brain == NULL)
		this->brain = NULL;
	else
		this->brain = new Brain(*obj.brain);
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
	if (this != &obj) {
		delete this->brain;
		this->_type = obj._type;
		if (obj.brain == NULL)
			this->brain = NULL;
		else
			this->brain = new Brain(*obj.brain);
	}
	std::cout << GREEN "Dog assigned" RESET << std::endl;
	return (*this);
}
