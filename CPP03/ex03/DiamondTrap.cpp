/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 20:31:20 by vtestut           #+#    #+#             */
/*   Updated: 2024/03/09 20:31:21 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/******************************************************************************/
/*								PRIVATE										  */
/******************************************************************************/


// void DiamondTrap:: () {
// }


/******************************************************************************/
/*								PUBLIC										  */
/******************************************************************************/


// void DiamondTrap:: () {
// }


/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/


//	Default Constructor
DiamondTrap::DiamondTrap(void) {}

//	Parametric Constructor
DiamondTrap::DiamondTrap(int const p1) : _n(p1) {}

//	Copy constructor
DiamondTrap::DiamondTrap(DiamondTrap const & src) {
	*this = src;
}
	
//	Default Destructor
DiamondTrap::~DiamondTrap(void) {}


/******************************************************************************/
/*							GETTERS & SETTERS								  */
/******************************************************************************/


int DiamondTrap::_getValue(void) const {
	return this->_n;
}

void DiamondTrap::setValue(int const p1) {
	this->_n = p1;
}


/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/


//	Assignation Operator
DiamondTrap &   DiamondTrap::operator=(DiamondTrap const & rhs) {
	this->_n = rhs._getValue();
	return *this;
}

//	Addition Operator
DiamondTrap DiamondTrap::operator+(DiamondTrap const & rhs) const {
  return DiamondTrap( this->_n + rhs._getValue());
}

//	Stream Redirection Operator
// std::ostream &  operator<<(std::ostream & out, DiamondTrap const & rhs) {
//	out << rhs._getValue(); // passer getValue en public
//	return ( out );
//}
