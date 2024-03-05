/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:43:12 by vtestut           #+#    #+#             */
/*   Updated: 2024/03/05 17:53:09 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/

//	! converts the fixed-point value to an integer value
int Fixed::toInt(void) const {
	return roundf(this->_raw / 256.0);
}

//	! converts the fixed-point value to a floating-point value
float Fixed::toFloat(void) const {
	return roundf(this->_raw / 256) + ((this->_raw % 256)) / 256.0;
}

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

//	Default Constructor
Fixed::Fixed(void) : _raw(0) {
	std::cout << "Default constructor called" << std::endl;
}

//	Copy Constructor
Fixed::Fixed(const Fixed & obj) {
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

//	! Int Constructor NEW converts p to the corresponding fpv
Fixed::Fixed(const int raw_) {
	std::cout << "Int constructor called" << std::endl;
	this->_raw = raw_ * 256; // ! raw_ << 8;
}

//	! Float Constructor NEW converts p to the corresponding fpv
Fixed::Fixed(const float raw_) {
	std::cout << "Float constructor called" << std::endl;
	int raw_int = (int)(raw_);
	int raw_dec = roundf((raw_ - (int)raw_)*256);
	this->_raw = raw_int * 256 + raw_dec;
}

//	Default Desctructor
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

/******************************************************************************/
/*							GETTERS & SETTERS								  */
/******************************************************************************/

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return ( this->_raw );
}


void Fixed::setRawBits(const int raw_) {
	std::cout << "setRawBits member funtion called" << std::endl;
	this->_raw = raw_;
	return ;
}

/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/

//	Assignment operator 
Fixed &	Fixed::operator=(const Fixed & obj) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
		this->_raw = obj.getRawBits();
	return (*this);
}

//	Insertion operator
std::ostream& operator<<(std::ostream& os, Fixed const & f) {
	std::cout << "Insertion operator called" << std::endl;
	os << f.toFloat();
	return os;
}
