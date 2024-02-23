#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <string>

# include "Weapon.hpp"

class HumanB {

	public:

		HumanB(std::string p1);

		void attack();
		void setWeapon(Weapon& ptr);
		
	private:

		std::string _name;
		Weapon*		_weaponTypePTR;
};

#endif