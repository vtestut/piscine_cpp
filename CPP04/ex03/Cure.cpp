#include "Cure.hpp"
#include <iostream>

/******************************************************************************/
/*								PUBLIC										  */
/******************************************************************************/

AMateria * Cure::clone() const {
	AMateria *	cureClone = new Cure();
	return (cureClone);
}

void Cure::use(ICharacter & target) {
	std::cout << GREEN "* heals " << target.getName() << "'s wounds *" RESET << std::endl;
}

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

Cure::Cure() : AMateria("cure") {
	std::cout << CYAN "Cure default constructor called." RESET << std::endl;
}

Cure::Cure(const Cure & obj) : AMateria("cure") {
	std::cout << CYAN "Cure copy constructor called." RESET << std::endl;
	*this = obj;
}

Cure::~Cure() {
	std::cout << CYAN "Cure destructor called." RESET << std::endl;
}

/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/

Cure & Cure::operator=(const Cure & obj) {
	std::cout << CYAN "Cure assignment operator called." RESET << std::endl;
	this->_type = obj._type;
	return (*this);
}
