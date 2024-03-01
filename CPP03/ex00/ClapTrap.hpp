#ifndef _CLAPTRAP_HPP
# define _CLAPTRAP_HPP

# include <iostream>
# include <iomanip>
# include <string>
//# include <>

/******************************************************************************/
/*									DEFINES									  */
/******************************************************************************/

# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define CYAN	"\033[36m"
# define YELLOW	"\033[93m"

# define RESET	"\033[0m"
# define CLEAR	"\033[2J\033[1;1H"

/******************************************************************************/
/*									CLASS									  */
/******************************************************************************/

class ClapTrap {

private:
	
	int	_hit = 10;
	int _nrj = 10;
	int _atk = 0;

	std::string _name;

	int	_getHitPoints(void) const;
	int _getEnergyPoints(void) const;
	int _getAttackPoints(void) const;
	std::string _getName(void) const;

public:

	ClapTrap(void);
	ClapTrap(std::string name_);
	ClapTrap(ClapTrap const & src);
	~ClapTrap(void);
	
	// void	setHitPoints(int const hit_);
	// void	setEnergyPoints(int const nrj_);
	// void	setAttackPoints(int const atk_);
	// std::string setName(std::string name_);

	void attack(const std::string& target);
	void takeDamage(int amount);
	void beRepaired(int amount);

	ClapTrap &	operator=(const ClapTrap & rhs);	

};

#endif
