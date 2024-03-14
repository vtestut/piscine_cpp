/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:43:06 by vtestut           #+#    #+#             */
/*   Updated: 2024/03/14 21:06:42 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CLAPTRAP_HPP
# define _CLAPTRAP_HPP

# include <iostream>

/******************************************************************************/
/*									DEFINES									  */
/******************************************************************************/

# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define CYAN	"\033[36m"
# define YELLOW	"\033[93m"

# define RESET	"\033[0m"
# define CLEAR	"\033[2J\033[1;1H"

# define ATK	0

/******************************************************************************/
/*									CLASS									  */
/******************************************************************************/

class ClapTrap {

private:
	
	unsigned int _hit;
	unsigned int _nrj;
	unsigned int _atk;

	std::string _name;

public:

	static const unsigned int _maxHit = 10;

	ClapTrap();
	ClapTrap(std::string name_);
	ClapTrap(const ClapTrap & obj);
	~ClapTrap();
	
	int	getHitPoints(void) const;
	int getEnergyPoints(void) const;
	int getAttackPoints(void) const;
	std::string getName(void) const;
	
	void setHitPoints(const int hit_);
	void setEnergyPoints(const int nrj_);
	void setAttackPoints(const int atk_);
	void setName(std::string name_);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	ClapTrap &	operator=(const ClapTrap & obj);	
};

#endif
