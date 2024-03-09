/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:30:18 by vtestut           #+#    #+#             */
/*   Updated: 2024/03/08 18:30:19 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  _FRAGTRAP_HPP
# define _FRAGTRAP_HPP

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

class FragTrap : public ClapTrap {

public:

	FragTrap(void);
	FragTrap(std::string name_);
	FragTrap(FragTrap const & src);
	~FragTrap(void);

	void highFivesGuys(void);

	FragTrap &	operator=(FragTrap const & rhs);
};

#endif
