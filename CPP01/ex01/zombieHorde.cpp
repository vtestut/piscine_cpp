#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
	
	Zombie* laHorde;

	if (N <= 0)
		return (NULL);
		
	//	en declarant un array de cette facon on ne peut pas initaliser 
	//	d'attributs via constructeur
	laHorde = new Zombie[N]; 
  	if (!laHorde)
		return (NULL);

	for (int i = 0; i < N; i++)
		laHorde[i].setName(name);
		
	return (laHorde);
}