#include "HumanB.hpp"

HumanB::HumanB(std::string p1) : _name(p1) {
	this->_weaponTypePTR = NULL;
}

void HumanB::setWeapon(Weapon& ptr) {
	this->_weaponTypePTR = &ptr;
}

void HumanB::attack(){
	if (this->_weaponTypePTR != NULL)
		std::cout << this->_name << " utilise : " << this->_weaponTypePTR->getType() << std::endl;
	else
		std::cout << this->_name << " utilise : " << std::endl;
}
