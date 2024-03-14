/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:30:18 by vtestut           #+#    #+#             */
/*   Updated: 2024/03/14 21:04:02 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  _FRAGTRAP_HPP
# define _FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {

public:

	FragTrap();
	FragTrap(std::string name_);
	FragTrap(const FragTrap & obj);
	~FragTrap();

	void highFivesGuys(void);

	FragTrap &	operator=(const FragTrap & obj);
};

#endif
