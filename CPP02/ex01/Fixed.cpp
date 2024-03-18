/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:43:12 by vtestut           #+#    #+#             */
/*   Updated: 2024/03/18 17:58:03 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/

float Fixed::toFloat(void) const { return (this->_value / 256.0); }

int Fixed::toInt(void) const { return (this->_value >> _bits); }

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

Fixed::Fixed(void) : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed & obj) /*: _value(obj._value)*/ {
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed::Fixed(const int n) : _value(n << 8) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n) : _value((int)roundf(256.0 * n)) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

/******************************************************************************/
/*								ACCESSORS									  */
/******************************************************************************/

int Fixed::getRawBits(void) const { return (this->_value); }

void Fixed::setRawBits(const int raw) { this->_value = raw; }

/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/

Fixed &	Fixed::operator=(const Fixed & obj) {
	std::cout << "Copy assignment operator called." << std::endl;
	this->_value = obj.getRawBits();
	// this->_value = obj._value;
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Fixed & n) {
	os << n.toFloat();
	return (os);
}
