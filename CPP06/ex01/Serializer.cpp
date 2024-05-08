#include "Serializer.hpp"

/******************************************************************************/
/*								PUBLIC										  */
/******************************************************************************/

uintptr_t Serializer::serialize(Data* ptr) {
	if (ptr == NULL) {
		std::cout << "Error: null pointer." << std::endl;
		return 0;
	}
	return (reinterpret_cast<uintptr_t>(ptr));
}

// converts unsigned int to Data*
Data* Serializer::deserialize(uintptr_t raw) {
	if (raw == 0) {
		std::cout << "Error: Attempt to deserialize from a null equivalent value." << std::endl;
		return NULL;
	}
	return (reinterpret_cast<Data*>(raw));
}

Serializer::~Serializer(void) {}

/******************************************************************************/
/*								PRIVATE										  */
/******************************************************************************/

Serializer::Serializer() {};

Serializer::Serializer(const Serializer &obj) { 
	*this = obj; 
};

/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/

Serializer& Serializer::operator = (Serializer const &obj) {
	(void)obj;
	return *this;
};
