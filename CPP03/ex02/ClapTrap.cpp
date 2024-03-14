/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:42:59 by vtestut           #+#    #+#             */
/*   Updated: 2024/03/14 21:06:42 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/

void ClapTrap::attack(const std::string & target) 
{
	if (_nrj <= 0) {
		std::cout << this->_name << " Can't attack. No energy points" << std::endl;
		return;
	} else if (_hit <= 0) {
		std::cout << this->_name << " Can't attack. is dead" << std::endl;
		return;	
	} else {
		std::cout << RED << this->_name << " attacks " << target << " causing " << this->_atk << " points of damage" RESET << std::endl;
		this->_nrj -= 1;
		return;
	}
}

void ClapTrap::takeDamage(unsigned int amount) 
{
	if (this->_hit == 0) {
		std::cout << YELLOW << this->_name << " is already lying in its blood" RESET << std::endl;
		return;
	} else if (amount >= this->_hit) {
		std::cout << YELLOW << this->_name << " takes " << amount << " damages and is KO" RESET << std::endl;
		this->_hit = 0; 
		return;
	} else {
		std::cout << YELLOW << this->_name << " takes " << amount << " damages and has now " << this->_hit - amount << " life points" RESET << std::endl;
		this->_hit = this->_hit - amount;
		return;
	}
}

void ClapTrap::beRepaired(unsigned int amount) 
{
	if (_nrj <= 0) {
		std::cout << GREEN << this->_name << " Can't repair. No energy" RESET << std::endl;
		return;
	} else if (_hit == 0) {
		std::cout << GREEN << this->_name << " Can't repair. is KO" RESET << std::endl;
		return;	
	} else if (amount == 0) {
		std::cout << GREEN << this->_name << " Can't repair 0. 1 Energy lost" RESET << std::endl;
		this->_nrj -= 1;
		return;
	} else if (amount > _maxHit) {
		amount = _maxHit - _hit;
		this->_nrj -= 1;
		this->_hit += amount;
		std::cout << GREEN << this->_name << " use a super potion to regain all its Hit points" RESET << std::endl;
		return;
	} else if (amount + _hit >= _maxHit) {
		std::cout << GREEN << this->_name << " use a +" << amount << "PV potion and is now full life" RESET << std::endl;
		amount = _maxHit - _hit;
		this->_nrj -= 1;
		this->_hit += amount;
		return;
	}
	this->_nrj -= 1;
	this->_hit += amount;
	std::cout << GREEN << this->_name << " use a potion to regain " << amount << " life points" << " and has now " << this->_hit << " life points" RESET << std::endl;
}

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

ClapTrap::ClapTrap(void) : _hit(10), _nrj(10), _atk(ATK) { 
	std::cout << "Default conctructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name_) : _hit(10) , _nrj(10), _atk(ATK), _name(name_) { 
	std::cout << "Parametric conctructor called for " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap & obj) {
	std::cout << "Copy conctructor called" << std::endl;
	*this = obj;
}

ClapTrap::~ClapTrap(void) { 
	if (this->_name == "") 
		std::cout << "Destructor called for unknown ClapTrap" << std::endl;	
	else 
		std::cout << "Destructor called for ClapTrap " << _name << std::endl;
}

/******************************************************************************/
/*							GETTERS	& SETTERS								  */
/******************************************************************************/

int ClapTrap::getHitPoints(void) const {return this->_hit;}
int ClapTrap::getEnergyPoints(void) const {return this->_nrj;}
int ClapTrap::getAttackPoints(void) const {return this->_atk;}
std::string ClapTrap::getName(void) const {return this->_name;}

void ClapTrap::setHitPoints(const int hit_) {this->_hit = hit_;}
void ClapTrap::setEnergyPoints(const int nrj_) {this->_nrj = nrj_;}
void ClapTrap::setAttackPoints(const int atk_) {this->_atk = atk_;}
void ClapTrap::setName(std::string name_) {this->_name = name_;}

/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/

ClapTrap & ClapTrap::operator= (const ClapTrap & obj) {
	std::cout << "Assignment operator called" << std::endl;
	if (this != &obj) {
		this->_name = obj._name;
		this->_hit = obj._hit;
		this->_nrj = obj._nrj;
		this->_atk = obj._atk;
	}
	return (*this);
};
