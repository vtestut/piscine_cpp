/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:47:36 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/24 18:47:37 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <string>

# include "Weapon.hpp"

class HumanB {

	public:

		HumanB(std::string p1);

		void attack();
		void setWeapon(Weapon& ptr);
		
	private:

		std::string _name;
		Weapon*		_weaponTypePTR;
};

#endif