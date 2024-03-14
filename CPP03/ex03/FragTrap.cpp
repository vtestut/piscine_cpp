/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:30:16 by vtestut           #+#    #+#             */
/*   Updated: 2024/03/14 21:15:41 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/

void FragTrap::highFivesGuys(void) {
	std::cout << this->_name << " does a positive highfive !" << std::endl;
}

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

FragTrap::FragTrap(void) : ClapTrap() {
	std::cout << "FragTrap default constuctor called" << std::endl;
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackPoints(30);
}

FragTrap::FragTrap(std::string name_) : ClapTrap(name_) {
	std::cout << "FragTrap parametric constructor called for " << _name << std::endl;
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackPoints(30);
}

FragTrap::FragTrap(const FragTrap & obj) : ClapTrap() {
	std::cout << "FragTrap copy constructor called for " << obj._name << std::endl;
	*this = obj;
}
	
FragTrap::~FragTrap(void) {
	if (this->_name == "") 
		std::cout << "Destructor called for unknown FragTrap" << std::endl;	
	else 
		std::cout << "Destructor called for FragTrap " << _name << std::endl;
}

/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/

FragTrap & FragTrap::operator=(const FragTrap & obj) {
	std::cout << "FragTrap assignment operator called" << std::endl;
	if (this != &obj) {
		this->_name = obj.getName();
		this->_hit = obj.getHitPoints();
		this->_nrj = obj.getEnergyPoints();
		this->_atk = obj.getAttackPoints();
	}
	return (*this);
}
