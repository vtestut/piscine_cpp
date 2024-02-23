#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <iomanip>
# include <string>

class Weapon {

	public:

		Weapon(std::string str);

		const std::string	&getType(void) const;
		void 				setType(std::string p1);

	private:

		std::string _type;
};

#endif