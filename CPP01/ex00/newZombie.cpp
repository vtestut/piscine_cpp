#include "Zombie.hpp"

Zombie* newZombie(std::string name) {

    Zombie* ptrZomb = new Zombie(name);
    return (ptrZomb);
} 
