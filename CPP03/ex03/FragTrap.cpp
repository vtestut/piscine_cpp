/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:30:16 by vtestut           #+#    #+#             */
/*   Updated: 2024/03/08 20:44:03 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/******************************************************************************/
/*								PUBLIC										  */
/******************************************************************************/

void FragTrap::highFivesGuys(void) {
	std::cout << "Positive highfive !" << std::endl;
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
		std::cout << "Destructor called for unknown ClapTrap" << std::endl;	
	else 
		std::cout << "Destructor called for " << _name << std::endl;
}

/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/

FragTrap & FragTrap::operator=(FragTrap const & src) {
	std::cout << "FragTrap assignment operator called" << std::endl;
	if (this != &src) {
		this->_name = src.getName();
		this->_hit = src.getHitPoints();
		this->_nrj = src.getEnergyPoints();
		this->_atk = src.getAttackPoints();
	}
	return (*this);
}
