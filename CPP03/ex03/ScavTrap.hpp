/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:10:55 by vtestut           #+#    #+#             */
/*   Updated: 2024/03/14 19:34:00 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  _SCAVTRAP_HPP
# define _SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {

public:

	ScavTrap(void);
	ScavTrap(std::string name_);
	ScavTrap(const ScavTrap & obj);
	~ScavTrap();

	void attack(const std::string& target);
	void guardGate(void);

	ScavTrap & operator=(const ScavTrap & obj);
};

#endif
