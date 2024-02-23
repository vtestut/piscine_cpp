#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <iomanip>

class Zombie {

	public:

		//	On peut declarer plusieurs constructeurs pour plus de 
		//	flexibilte lors de l'initialisation d'un objet
		Zombie();
		Zombie(std::string p1);
		~Zombie(void);

		void announce(void);
		void setName(std::string p1);

	private:

		std::string _name;
};

	Zombie* zombieHorde( int N, std::string name );
	
#endif