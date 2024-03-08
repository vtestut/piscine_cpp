/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:30:23 by vtestut           #+#    #+#             */
/*   Updated: 2024/03/08 18:30:24 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  _SCAVTRAP_HPP
# define _SCAVTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

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

class ScavTrap : public ClapTrap {

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
