/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:47:17 by vtestut           #+#    #+#             */
/*   Updated: 2024/03/08 18:24:52 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// ! modifier dans l'exo 00 la fctn attack : nrj-=1
 

/******************************************************************************/
/*								PUBLIC										  */
/******************************************************************************/

void ScavTrap::guardGate(void) {
	std::cout << this->_name << " is now in gate keeper mode. You shall not pass !" << std::endl;
}

void ScavTrap::attack(const std::string & target) 
{
	if (_nrj <= 0) {
		std::cout << this->_name << " Can't attack. Need more energy, more passion, more energy, more passion" << std::endl;
		return;
	} else {
		this->_nrj -= 1;
		std::cout << RED << this->_name << " goes nuts on " << target << " causing it " << this->_atk << " points of damage" RESET << std::endl;
		return;
	}
}

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

ScavTrap::ScavTrap(void) : ClapTrap() {
	std::cout << "ScavTrap default constuctor called" << std::endl;
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackPoints(20);
}

ScavTrap::ScavTrap(std::string name_) : ClapTrap(name_) {
	std::cout << "ScavTrap parametric constructor called for " << _name << std::endl;
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackPoints(20);
}

ScavTrap::ScavTrap(const ScavTrap & obj) : ClapTrap() {
	std::cout << "ScavTrap copy constructor called for " << obj._name << std::endl;
	*this = obj;
}

ScavTrap::~ScavTrap(void) {
	if (this->_name == "") 
		std::cout << "Destructor called for unknown ClapTrap" << std::endl;	
	else 
		std::cout << "Destructor called for " << _name << std::endl;
}

/******************************************************************************/
/*							GETTERS & SETTERS								  */
/******************************************************************************/




/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/

ScavTrap & ScavTrap::operator=(ScavTrap const & obj) {
	std::cout << "ScavTrap assignment operator called" << std::endl;
	if (this != &obj) {
		this->_name = obj.getName();
		this->_hit = obj.getHitPoints();
		this->_nrj = obj.getEnergyPoints();
		this->_atk = obj.getAttackPoints();
	}
	return (*this);
}
