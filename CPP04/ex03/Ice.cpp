#include "Ice.hpp"
#include <iostream>

/******************************************************************************/
/*								PUBLIC										  */
/******************************************************************************/

AMateria * Ice::clone() const {
	AMateria * iceClone = new Ice();
	return (iceClone);
}

void Ice::use(ICharacter & target) {
	std::cout << YELLOW "* shoots an ice bolt at " << target.getName() << " *" RESET << std::endl;
}

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

Ice::Ice() : AMateria("ice") {
	// std::cout << CYAN "Ice default constructor called." RESET << std::endl;
}

Ice::Ice(const Ice & obj) : AMateria("ice") {
	// std::cout << CYAN "Ice copy constructor called." RESET << std::endl;
	*this = obj;
}

Ice::~Ice() {
	// std::cout << CYAN "Ice destructor called." RESET << std::endl;
}

/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/

Ice & Ice::operator=(const Ice & obj) {
	// std::cout << CYAN "Ice assignment operator called." RESET << std::endl;
	this->_type = obj._type;
	return (*this);
}