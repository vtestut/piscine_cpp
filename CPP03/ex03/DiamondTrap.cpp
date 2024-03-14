/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 20:31:20 by vtestut           #+#    #+#             */
/*   Updated: 2024/03/14 21:23:06 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/


void DiamondTrap::whoAmI(void) {
	if (this->_hit == 0)
		std::cout << this->_name << ", grandchild of " << ClapTrap::_name << " rests in pieces." << std::endl;
	else
		std::cout << "I am " << this->_name << "grandchild of " << ClapTrap::_name << std::endl;
}


/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

DiamondTrap::DiamondTrap(void) : ScavTrap(), FragTrap() {
	std::cout << "DiamondTrap default constuctor called" << std::endl;
	this->_hit = FragTrap::getHitPoints();
	this->_nrj = ScavTrap::getEnergyPoints();
	this->_atk = FragTrap::getAttackPoints();
}

DiamondTrap::DiamondTrap(std::string name_) :	ClapTrap(name_ + "_clap_name"), 
												ScavTrap(name_ + "_scav_name"),
												FragTrap(name_ + "_frag_name"),
												_name(name_) {
	std::cout << "DiamondTrap parametric constructor called for " << _name << std::endl;
	this->_hit = FragTrap::getHitPoints();
	this->_nrj = ScavTrap::getEnergyPoints();
	this->_atk = FragTrap::getAttackPoints();
}

DiamondTrap::DiamondTrap(const DiamondTrap & obj) {
	std::cout << "DiamondTrap copy constructor called for " << obj._name << std::endl;
	*this = obj;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "Destructor called for " << this->_name << std::endl;
}

/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/

DiamondTrap & DiamondTrap::operator=(const DiamondTrap & obj) {
	std::cout << "DiamondTrap assignment operator called" << std::endl;
	if (this != &obj) {
		this->_name = obj.getName();
		this->_hit = obj.getHitPoints();
		this->_nrj = obj.getEnergyPoints();
		this->_atk = obj.getAttackPoints();
	}
	return (*this);
}
