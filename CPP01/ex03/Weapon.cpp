#include "Weapon.hpp"

/*	Initialization list
	Pour initaliser des attributs lors de la creation de l'instance,
	ajouter ' : ' apres les parametres puis preciser l'attribut a initialiser
	suivi du parametre passee au constructeur entre parenthese */
Weapon::Weapon(std::string str) : _type(str) {}

//	Retourne une reference constante sur _type . 
//	ou : std::string const & Weapon::getType(void)
const std::string & Weapon::getType(void) const
{
	return (this->_type);
}

void Weapon::setType(std::string p1) 
{
	this->_type = p1;
}
