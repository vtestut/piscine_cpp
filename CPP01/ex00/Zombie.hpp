/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:40:34 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/24 18:40:35 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <iomanip>

class Zombie {

	public:

	/*	Les constructeurs et destructeurs n'ont pas de type de retour
		Si on ne precise pas de constructeur ou destructeur, au debut et
		a la fin du program des constr et destr par defaut seront appeles */
		Zombie(std::string p1);
		~Zombie(void);

		void	announce(void);

	private:

		std::string	_name;
};

	void	randomChump(std::string name);
	Zombie*	newZombie(std::string name);
	
#endif