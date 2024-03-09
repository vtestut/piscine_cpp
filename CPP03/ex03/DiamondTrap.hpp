/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 20:31:23 by vtestut           #+#    #+#             */
/*   Updated: 2024/03/09 20:31:24 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  _DIAMONDTRAP_HPP
# define _DIAMONDTRAP_HPP

# include <iostream>
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

class DiamondTrap {

private:
	
	int	_n;
	int	_getValue(void) const;

public:

	DiamondTrap(void);
	DiamondTrap(int const p1);
	DiamondTrap(DiamondTrap const & src);
	~DiamondTrap(void);
	

	void	setValue(int const p1);

	DiamondTrap &	operator=(DiamondTrap const & rhs);
	DiamondTrap		operator+(DiamondTrap const & rhs) const;	

};

/******************************************************************************/
/*									PROTOYPES								  */
/******************************************************************************/

// std::ostream &	operator<<(std::ostream & out, DiamondTrap const & i);

#endif
