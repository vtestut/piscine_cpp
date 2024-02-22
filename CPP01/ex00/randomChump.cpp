#include "Zombie.hpp"

void randomChump(std::string name) {

    Zombie newInstance(name);
    newInstance.announce();
    return;
}