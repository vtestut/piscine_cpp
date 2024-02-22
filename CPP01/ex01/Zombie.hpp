#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <iomanip>

class Zombie {

	public:
		Zombie(std::string p1);
		~Zombie(void);

		void	announce(void);

	private:

		std::string	_name;
};

	// void	randomChump(std::string name);
	// Zombie*	newZombie(std::string name);
	Zombie* zombieHorde( int N, std::string name );
	
#endif