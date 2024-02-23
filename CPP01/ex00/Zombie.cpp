#include "Zombie.hpp"

//  Les constructeurs et destructeurs n'ont pas de type de retour

Zombie::Zombie(std::string p1) : _name(p1) {
    std::cout << this->_name << "\t: Constructed" << std::endl;
}

Zombie::~Zombie(void) {
    std::cout << this->_name << "\t: Destructed" << std::endl;
}

void Zombie::announce(void) {
    std::cout << this->_name << "\t: BraiiiiiiinnnzzzZ..." << std::endl;
    return;
}
