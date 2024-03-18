/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:43:12 by vtestut           #+#    #+#             */
/*   Updated: 2024/03/18 17:48:35 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

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

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

/******************************************************************************/
/*								ACCESSORS									  */
/******************************************************************************/

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called." << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(const int raw) {
	std::cout << "setRawBits member funtion called." << std::endl;
	this->_value = raw;
}

/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/

Fixed &	Fixed::operator=(const Fixed & obj) {
	std::cout << "Copy assignment operator called." << std::endl;
	this->_value = obj.getRawBits();
	// this->_value = obj._value;
	return (*this);
}
