/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:43:12 by vtestut           #+#    #+#             */
/*   Updated: 2024/03/04 18:51:14 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

//	Default Constructor
Fixed::Fixed(void) : _raw(0) {
	std::cout << "Default constructor called." << std::endl;
}

//	Copy Constructor
Fixed::Fixed(const Fixed & obj) {
	std::cout << "Copy constructor called." << std::endl;
	*this = obj;
}

//	Default Desctructor
Fixed::~Fixed() {
	std::cout << "Destructor called." << std::endl;
}


/******************************************************************************/
/*							GETTERS & SETTERS								  */
/******************************************************************************/


int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called." << std::endl;
	return ( this->_raw );
}

void	Fixed::setRawBits(const int raw_) {
	std::cout << "setRawBits member funtion called." << std::endl;
	this->_raw = raw_;
	return ;
}

/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/

Fixed &	Fixed::operator=(const Fixed & obj) {
	std::cout << "Copy assignment operator called." << std::endl;
	if (this != &obj)
		this->_raw = obj.getRawBits();
	return (*this);
}
