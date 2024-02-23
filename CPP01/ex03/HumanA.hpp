#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include <string>

# include "Weapon.hpp"

class HumanA {

	public:

		HumanA(std::string p1, Weapon& p2);
		
		void attack();

	private:

		std::string _name;
		Weapon&		_weaponTypeREF;
};

#endif