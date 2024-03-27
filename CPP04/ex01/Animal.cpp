#include "Animal.hpp"

/******************************************************************************/
/*								PUBLIC										  */
/******************************************************************************/

void Animal::makeSound () const {
  std::cout << "amimal noise" << std::endl;
}

/******************************************************************************/
/*								ACCESSORS									  */
/******************************************************************************/

std::string Animal::getType() const {
  return (this->_type);
}

void Animal::setType(std::string newType) {
  this->_type = newType;
}

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

Animal::Animal() : _type("Animal") {
	std::cout << GREEN "Animal constructed" RESET << std::endl;
}

Animal::Animal(const Animal & obj) : _type(obj._type) {
	std::cout << GREEN "Animal copied" RESET << std::endl;
}

Animal::~Animal() {
	std::cout << RED "Animal destructed" RESET << std::endl;
}

/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/

Animal & Animal::operator=(const Animal & obj) {
	if (this != &obj)
		this->_type = obj._type;
	std::cout << GREEN "Animal assigned" RESET << std::endl;
	return (*this);
}

// Animal& Animal::operator = (Animal const &ref) {
//   this->type = ref.type;
//   std::cout << "Animal      assignment operator   (type = " << this->type << ") VIRTUAL" << std::endl;
//   return *this;
// }




