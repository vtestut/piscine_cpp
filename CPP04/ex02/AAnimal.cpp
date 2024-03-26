#include "AAnimal.hpp"

/******************************************************************************/
/*								PUBLIC FUNCTIONS							  */
/******************************************************************************/

std::string AAnimal::getType() const { 
	return (this->type);
}

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

AAnimal::AAnimal() : type("AAnimal") {
	std::cout << "AAnimal constructed.\n";
}

AAnimal::AAnimal(const AAnimal& aanimal) : type(aanimal.type) {
	std::cout << "AAnimal copied.\n";
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructed.\n";
}

/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/

AAnimal& AAnimal::operator=(AAnimal const& aanimal) {
	if (this != &aanimal)
		this->type = aanimal.type;
	std::cout << "AAnimal assigned.\n";
	return (*this);
}

