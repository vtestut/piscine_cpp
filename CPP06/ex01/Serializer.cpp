#include "Serializer.hpp"

/******************************************************************************/
/*								PRIVATE										  */
/******************************************************************************/

Serializer::Serializer() {};

Serializer::Serializer(const Serializer &obj) { 
	*this = obj; 
};

Serializer& Serializer::operator = (Serializer const &obj) {
	(void)obj;
	return *this;
};

/******************************************************************************/
/*								PUBLIC										  */
/******************************************************************************/
/*	uintptr_t
- 	permet de stocker l'adresse d'un pointeur sous forme de nombre (valeur entiere) entier puis 
  	reconvertir en pointeur original sans changer la valeur
- 	permet la serialisation de pointeurs, ex : convertir un ptr en entier pour le stocker puis 
	le passer a une fctn qui attend un entier

	reinterpret_cast
-	forme de casting qui converti un type de ptr en un autre 
-	permet de traiter un bloc de mémoire comme s'il était d'un autre type, 
	sans changer le contenu binaire de la mémoire. 
	Cela signifie que reinterpret_cast ne modifie pas les bits; 
	il change juste la façon dont le compilateur traite ces bits.
*/
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

Serializer::~Serializer(void) {}


