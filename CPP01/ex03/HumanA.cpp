#include "HumanA.hpp"

HumanA::HumanA(std::string p1, Weapon& p2) : _name(p1), _weaponTypeREF(p2) {}

void HumanA::attack(void) {
	std::cout << this->_name << " utilise : ";
	std::cout << this->_weaponTypeREF.getType() << std::endl;
}
