#include "Serializer.hpp"

/******************************************************************************/
/*								PRIVATE										  */
/******************************************************************************/

Serializer::Serializer(const Serializer& obj) { 
	*this = obj; 
};

Serializer& Serializer::operator = (const Serializer& obj) {
	(void)obj;
	return *this;
};

/******************************************************************************/
/*								PUBLIC										  */
/******************************************************************************/

uintptr_t Serializer::serialize(Data* ptr) {
	if (!ptr) {
		std::cout << "Error null ptr" << std::endl;
		return 0;
	}
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
	if (!raw) {
		std::cout << "Error null value" << std::endl;
		return NULL;
	}
	return reinterpret_cast<Data*>(raw);
}
