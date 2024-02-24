/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:47:20 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/24 18:47:21 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string p1, Weapon& p2) : _name(p1), _weaponTypeREF(p2) {}

void HumanA::attack(void) {
	std::cout << this->_name << " utilise : ";
	std::cout << this->_weaponTypeREF.getType() << std::endl;
}
