/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:51:26 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/24 18:53:08 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string str) : _type(str) {}

//	Retourne une reference constante sur _type
const std::string & Weapon::getType(void) const // ou : std::string const & Weapon::getType(void) 
{
	return (this->_type);
}

void Weapon::setType(std::string p1) 
{
	this->_type = p1;
}
