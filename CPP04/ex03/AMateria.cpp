#include "AMateria.hpp"
#include <iostream>
#include <string>

/******************************************************************************/
/*								PUBLIC										  */
/******************************************************************************/

void	AMateria::use(ICharacter & target) {
	std::cout << RED "* An unknown materia is being used against"
		<< target.getName() << " *" RESET << std::endl;
	return ;
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

AMateria::AMateria(void) : _type("unknown")
{
	std::cout << CYAN "AMateria default constructor called." RESET << std::endl;
	return ;
}

// ! While assigning a Materia to another, copying the type doesn’t make sense
AMateria::AMateria(AMateria const & src) {
  *this = src;
  std::cout << "Materia copy constructor called  (type = " << _type << ")" << std::endl;
} 

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout << CYAN "AMateria type constructor called." RESET << std::endl;
	return ;
}

AMateria::~AMateria(void)
{
	std::cout << CYAN "AMateria destructor called." RESET << std::endl;
	return ;
}

/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/

AMateria &	AMateria::operator=(AMateria const & src)
{
	std::cout << GREEN "AMateria assignment operator overload called." RESET
		<< std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}