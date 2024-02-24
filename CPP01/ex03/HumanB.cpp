/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:47:33 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/24 18:47:34 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string p1) : _name(p1) {
	this->_weaponTypePTR = NULL;
}

void HumanB::setWeapon(Weapon& ptr) {
	this->_weaponTypePTR = &ptr;
}

void HumanB::attack(){
	if (this->_weaponTypePTR != NULL)
		std::cout << this->_name << " utilise : " << this->_weaponTypePTR->getType() << std::endl;
	else
		std::cout << this->_name << " utilise : " << std::endl;
}
