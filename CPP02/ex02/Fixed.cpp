/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:41:36 by vtestut           #+#    #+#             */
/*   Updated: 2024/03/18 18:00:58 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/

float Fixed::toFloat(void) const { return (this->_value / 256.0); }

int Fixed::toInt(void) const { return (this->_value >> _bits); }

Fixed &	Fixed::min(Fixed & a, Fixed & b) { return a < b ? a : b; }

Fixed &	Fixed::max(Fixed & a, Fixed & b) { return a > b ? a : b; }

const Fixed & Fixed::min(const Fixed & a, const Fixed & b) { return a < b ? a : b; }

const Fixed & Fixed::max(const Fixed & a, const Fixed & b) { return a > b ? a : b; }

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

Fixed::Fixed(void) : _value(0) {}

Fixed::Fixed(const Fixed & obj) : _value(obj._value) {}

Fixed::Fixed(const int n) : _value(n << 8) {}

Fixed::Fixed(const float n) : _value((int)roundf(256.0 * n)) {}

Fixed::~Fixed(void) {}

/******************************************************************************/
/*								ACCESSORS									  */
/******************************************************************************/

int Fixed::getRawBits(void) const { return (this->_value); }

void Fixed::setRawBits(const int raw) { this->_value = raw; }

/******************************************************************************/
/*								OPERATOR OVERLOAD						  	  */
/******************************************************************************/

Fixed &	Fixed::operator=(const Fixed & obj) {
	this->_value = obj._value;
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Fixed & n) {
	os << n.toFloat();
	return (os);
}

Fixed Fixed::operator+(const Fixed & obj) { return Fixed(this->toFloat() + obj.toFloat()); }

Fixed Fixed::operator-(const Fixed & obj) { return Fixed(this->toFloat() - obj.toFloat()); }

Fixed Fixed::operator*(const Fixed & obj) { return Fixed(this->toFloat() * obj.toFloat()); }

Fixed Fixed::operator/(const Fixed & obj) { return Fixed(this->toFloat() / obj.toFloat()); }

Fixed &	Fixed::operator++(void) {	// ++i	pre incrementation
	++this->_value;
	return (*this);
}

Fixed &	Fixed::operator--(void) {	// --i	pre decrementation
	--this->_value;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed tmp = *this;
	this->_value++;
	return (tmp);
}

Fixed Fixed::operator--(int) {
	Fixed tmp = *this;
	this->_value--;
	return (tmp);
}

bool Fixed::operator>(const Fixed & obj) const { return (this->_value > obj.getRawBits()); }

bool Fixed::operator<(const Fixed & obj) const { return (this->_value < obj.getRawBits()); }

bool Fixed::operator>=(const Fixed & obj) const { return (this->_value >= obj.getRawBits()); }

bool Fixed::operator<=(const Fixed & obj) const { return (this->_value <= obj.getRawBits()); }

bool Fixed::operator==(const Fixed & obj) const { return (this->_value == obj.getRawBits()); }

bool Fixed::operator!=(const Fixed & obj) const { return (this->_value != obj.getRawBits()); }
