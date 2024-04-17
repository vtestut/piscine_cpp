#include "AMateria.hpp"
#include <iostream>
#include <string>


/******************************************************************************/
/*							ACCESSORS										  */
/******************************************************************************/

std::string const & AMateria::getType() const {
	return (this->_type);
}

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

AMateria::AMateria() : _type("unknown") {}

AMateria::AMateria(const AMateria & obj) {
	*this = obj;
} 

AMateria::AMateria(std::string const & type) : _type(type) {}

AMateria::~AMateria() {}

/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/

AMateria & AMateria::operator=(const AMateria & obj) {
	if (this != &obj)
		this->_type = obj._type;
	return (*this);
}