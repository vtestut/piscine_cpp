/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:43:06 by vtestut           #+#    #+#             */
/*   Updated: 2024/03/07 19:30:38 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CLAPTRAP_HPP
# define _CLAPTRAP_HPP

# include <iostream>
# include <iomanip>
# include <string>

/******************************************************************************/
/*									DEFINES									  */
/******************************************************************************/

# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define CYAN	"\033[36m"
# define YELLOW	"\033[93m"

# define RESET	"\033[0m"
# define CLEAR	"\033[2J\033[1;1H"

# define ATK	2

/******************************************************************************/
/*									CLASS									  */
/******************************************************************************/

class ClapTrap {

protected:
	
	unsigned int _hit;
	unsigned int _nrj;
	unsigned int _atk;

	std::string _name;

public:

	ClapTrap(void);
	ClapTrap(std::string name_);
	ClapTrap(const ClapTrap & obj);
	~ClapTrap();
	
	int	getHitPoints(void) const;
	int getEnergyPoints(void) const;
	int getAttackPoints(void) const;
	std::string getName(void) const;
	
	void	setHitPoints(int const hit_);
	void	setEnergyPoints(int const nrj_);
	void	setAttackPoints(int const atk_);
	void	setName(std::string name_);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	ClapTrap &	operator=(const ClapTrap & rhs);	
};

#endif
