#include "Zombie.hpp"

int main()
{
	int N = 3;
	
	Zombie	*laHorde = zombieHorde(N, "Patrick");
	if (!laHorde)
		return (1);
	
	for (size_t i = 0; i < (size_t)N; i++) {
		std::cout << "zombie " << i+1 << " : ";
		laHorde[i].announce();
	}
	
	delete [] laHorde;
	
	return (0);
}