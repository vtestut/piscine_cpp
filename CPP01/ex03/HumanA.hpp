/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:47:26 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/24 18:47:27 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include <string>

# include "Weapon.hpp"

class HumanA {

	public:

		HumanA(std::string p1, Weapon& p2);
		
		void attack();

	private:

		std::string _name;
		Weapon&		_weaponTypeREF;
};

#endif