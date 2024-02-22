#include "Zombie.hpp"

int main( void ) 
{
    Zombie Foo("Foo");
    Foo.announce();
    Foo.announce();
    Foo.announce();

    std::cout << std::endl;

    Zombie* zombie_ptr = newZombie("PTR");
    zombie_ptr->announce();
    zombie_ptr->announce();

    std::cout << std::endl;

    randomChump("CHUMP");

    std::cout << std::endl;

    delete zombie_ptr;
    return (0);
}