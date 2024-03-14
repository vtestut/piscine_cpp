/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 20:31:23 by vtestut           #+#    #+#             */
/*   Updated: 2024/03/14 21:12:48 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  _DIAMONDTRAP_HPP
# define _DIAMONDTRAP_HPP

# include <iostream>
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {

private:
	
	std::string _name;
	
public:

	DiamondTrap();
	DiamondTrap(std::string name_);
	DiamondTrap(const DiamondTrap & obj);
	~DiamondTrap();

	using	ScavTrap::attack;

	void	whoAmI(void);
	
	DiamondTrap & operator=(const DiamondTrap & obj);
};

#endif
