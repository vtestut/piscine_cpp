/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:41:36 by vtestut           #+#    #+#             */
/*   Updated: 2024/03/05 17:52:07 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/

//	! converts the fixed-point value to an integer value
int Fixed::toInt(void) const {
	return (this->_raw >> Fixed::_bits);	
}

//	! converts the fixed-point value to a floating-point value
float Fixed::toFloat(void) const {
	return ((float)this->_raw / (1 << _bits));
}

Fixed &	Fixed::min(Fixed & lhs, Fixed & rhs) {
	if (lhs <= rhs)
		return (lhs);
	return (rhs);
}

Fixed &	Fixed::max(Fixed & lhs, Fixed & rhs) {
	if (lhs >= rhs)
		return (lhs);
	return (rhs);
}

const Fixed & Fixed::min(const Fixed & lhs, const Fixed & rhs) {
	if (lhs <= rhs)
		return (lhs);
	return (rhs);
}

const Fixed & Fixed::max(const Fixed & lhs, const Fixed & rhs) {
	if (lhs >= rhs)
		return (lhs);
	return (rhs);
}

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

//	Default Constructor
Fixed::Fixed(void) : _raw(0) {
	// std::cout << "Default constructor called" << std::endl;
}

//	Copy Constructor
Fixed::Fixed(const Fixed & obj) {
	// std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

//	Int Constructor
Fixed::Fixed(const int n) : _raw(n << _bits) {
	// std::cout << "Int constructor called" << std::endl;
}

//	Float Constructor
Fixed::Fixed(const float f) : _raw(roundf(f * (1 << _bits))) {
	// std::cout << "Float constructor called" << std::endl;
}

//	Default Desctructor
Fixed::~Fixed(void) {
	// std::cout << "Destructor called" << std::endl;
}

/******************************************************************************/
/*								GETTERS	& SETTERS							  */
/******************************************************************************/

int Fixed::getRawBits(void) const {
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_raw);
}

void Fixed::setRawBits(int const raw_) {
	// std::cout << "setRawBits member funtion called." << std::endl;
	this->_raw = raw_;
}

/******************************************************************************/
/*								OPERATOR OVERLOAD						  	  */
/******************************************************************************/

Fixed &	Fixed::operator=(const Fixed & obj) {
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
		this->_raw = obj.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Fixed & f) {
	// std::cout << "Insertion operator called" << std::endl;
	os << f.toFloat();
	return (os);
}

Fixed Fixed::operator+(const Fixed & rhs) const {
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator-(const Fixed & rhs) const {
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator*(const Fixed & rhs) const {
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(const Fixed & rhs) const {
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed &	Fixed::operator++(void) {	// ++i	pre incrementation
	this->_raw += 1;
	return (*this);
}

Fixed &	Fixed::operator--(void) {	// --i	pre decrementation
	this->_raw -= 1;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	++(*this);
	return (tmp);
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	--(*this);
	return (tmp);
}

bool Fixed::operator>(const Fixed & rhs) const {
	return (this->_raw > rhs.getRawBits());
}

bool Fixed::operator<(const Fixed & rhs) const {
	return (this->_raw < rhs.getRawBits());
}

bool Fixed::operator>=(const Fixed & rhs) const {
	return (this->_raw >= rhs.getRawBits());
}

bool Fixed::operator<=(const Fixed & rhs) const {
	return (this->_raw <= rhs.getRawBits());
}

bool Fixed::operator==(const Fixed & rhs) const {
	return (this->_raw == rhs.getRawBits());
}

bool Fixed::operator!=(const Fixed & rhs) const {
	return (this->_raw != rhs.getRawBits());
}
