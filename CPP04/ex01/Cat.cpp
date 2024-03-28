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

std::string Cat::getIdea(int idx) const {
	if (this->brain == NULL)
		throw std::logic_error("Brain pointer is NULL");
	if (idx < 0 || idx >= NB_IDEAS)
		throw std::out_of_range("ideas[idx] is out of range");
	return (this->brain->ideas[idx]);
}

void Cat::setIdea(int idx, std::string idea) {
	if (this->brain == NULL)
		throw std::logic_error("Brain pointer is NULL");
	if (idx < 0 || idx >= NB_IDEAS)
		throw std::out_of_range("ideas[idx] is out of range");
	this->brain->ideas[idx] = idea;
}

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

Cat::Cat() {
	this->_type = "Cat";
	this->brain = new Brain();
	std::cout << GREEN "Cat constructed" RESET << std::endl;
}

Cat::Cat(const Cat & obj) {
	this->_type = obj._type;
	if (obj.brain == NULL)
		this->brain = NULL;
	else
		this->brain = new Brain(*obj.brain);
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
	if (this != &obj) {
		delete this->brain;
		this->_type = obj._type;
		if (obj.brain == NULL)
			this->brain = NULL;
		else
			this->brain = new Brain(*obj.brain);
	}
	std::cout << GREEN "Cat assigned" RESET << std::endl;
	return (*this);
}
