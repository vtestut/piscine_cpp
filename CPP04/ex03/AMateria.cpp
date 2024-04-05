#include "AMateria.hpp"
#include <iostream>
#include <string>

/******************************************************************************/
/*								PUBLIC										  */
/******************************************************************************/

void	AMateria::use(ICharacter & target) {
	std::cout << RED "* An unknown materia is being used against"
		<< target.getName() << " *" RESET << std::endl;
}

/******************************************************************************/
/*							ACCESSORS										  */
/******************************************************************************/

std::string AMateria::getType() const {
	return (this->_type);
}

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

AMateria::AMateria() : _type("unknown") {
	std::cout << CYAN "AMateria default constructor called." RESET << std::endl;
}

// ! While assigning a Materia to another, copying the type doesn’t make sense
AMateria::AMateria(const AMateria & obj) {
  *this = obj;
  std::cout << "Materia copy constructor called (type = " << _type << ")" << std::endl;
} 

AMateria::AMateria(std::string const & type) : _type(type) {
	std::cout << CYAN "AMateria type constructor called." RESET << std::endl;
}

AMateria::~AMateria() {
	std::cout << CYAN "AMateria destructor called." RESET << std::endl;
}

/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/

AMateria & AMateria::operator=(const AMateria & obj) {
	std::cout << GREEN "AMateria assignment operator overload called." RESET << std::endl;
	if (this != &obj)
		this->_type = obj._type;
	return (*this);
}