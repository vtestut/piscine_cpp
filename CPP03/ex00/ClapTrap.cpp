/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:42:59 by vtestut           #+#    #+#             */
/*   Updated: 2024/03/05 21:20:43 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/

void ClapTrap::attack(const std::string & target) {
	// cause the target to lose damage
	// need 1 nrj
	this->_nrj -= 1;
	if (_nrj <= 0) {
		std::cout << this->_name << "  Can't attack. No energy points" << std::endl;
		return;
	}
	std::cout	<< "ClapTrap " << this->_name << " attacks " << target 
				<< " causing " << this->_atk << " points of damage" << std::endl;
}

void ClapTrap::takeDamage(int amount) {
	if (amount <= 0) {
		std::cout << "Attack will have no effect" << std::endl;
		return;
	}
	int life = this->_hit - amount;
	if (life == 0)
		std::cout << this->_name << " is already KO" << std::endl;
	else if (life <= 0) {
		std::cout << this->_name << " take " << amount << " damage and is KO" << std::endl;
		this->_hit = 0; 
	} else if (life > 0) {
		std::cout << this->_name << " take " << amount << " damages and have now " << life << " life points" << std::endl;
		this->_hit = life; 
	}
}

void ClapTrap::beRepaired(int amount) {
	// win n hit
	// need 1 nrj
	this->_nrj -= 1;
	if (_nrj <= 0) {
		std::cout << this->_name << "  Can't repaire. No energy points" << std::endl;
		return;
	} else if (amount <= 0)
		return;
	this->_hit += amount;
	std::cout << this->_name << " use a potion to regain " << amount << " hit points" << std::endl;
	std::cout << this->_name << " has now " << this->_hit << " hit points" << std::endl;
}

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

ClapTrap::ClapTrap(void) : _hit(10), _nrj(10), _atk(0) { 
	std::cout << "Default conctructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name_) : _hit(10) , _nrj(10), _atk(0), _name(name_) { 
	std::cout << "Conctructor called for " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap & obj) {
	std::cout << "Copy conctructor called" << std::endl;
	*this = obj;
}

ClapTrap::~ClapTrap(void) { 
	if (this->_name == "") 
		std::cout << "Destructor called for unknown ClapTrap" << std::endl;	
	else 
		std::cout << "Destructor called for " << _name << std::endl;
	
		
}

/******************************************************************************/
/*							GETTERS	& SETTERS								  */
/******************************************************************************/

int ClapTrap::getHitPoints(void) const {return this->_hit;}
int ClapTrap::getEnergyPoints(void) const {return this->_nrj;}
int ClapTrap::getAttackPoints(void) const {return this->_atk;}
std::string ClapTrap::getName(void) const {return this->_name;}

// void ClapTrap::setHitPoints(int const hit_) {this->_hit = hit_;}
// void ClapTrap::setEnergyPoints(int const nrj_) {this->_nrj = nrj_;}
// void ClapTrap::setAttackPoints(int const atk_) {this->_atk = atk_;}
// std::string ClapTrap::setName(std::string name_) {this->_name = name_;}

/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/

//	Assignation Operator
ClapTrap& ClapTrap::operator= (const ClapTrap & rhs) {
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs) {
		this->_name = rhs._name;
		this->_hit = rhs._hit;
		this->_nrj = rhs._nrj;
		this->_atk = rhs._atk;
	}
	return (*this);
};
