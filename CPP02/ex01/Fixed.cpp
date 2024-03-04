/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:43:12 by vtestut           #+#    #+#             */
/*   Updated: 2024/03/04 20:32:31 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/

// converts the fixed-point value to a floating-point value
float Fixed::toFloat(void) const {
  return roundf(this->_raw / 256) + ((this->_raw % 256)) / 256.0;
}

// converts the fixed-point value to an integer value
int Fixed::toInt(void) const {
  return roundf(this->_raw / 256.0);
}

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

//	Default Constructor
Fixed::Fixed(void) : _raw(0) {
	std::cout << "Default constructor called." << std::endl;
}

// NEW converts p to the corresponding fpv
Fixed::Fixed(const int raw_) {
  std::cout << "Int constructor called" << std::endl;
  this->_raw = raw_ * 256; // raw_ << 8;
}

// NEW converts p to the corresponding fpv
Fixed::Fixed(const float raw_) {
  std::cout << "Float constructor called"       << std::endl;
  int raw_int = (int)(raw_);
  int raw_dec = roundf((raw_ - (int)raw_)*256);
  this->_raw = raw_int * 256 + raw_dec;
}

//	Copy Constructor
Fixed::Fixed(Fixed const & obj) {
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

void	Fixed::setRawBits(int const raw_) {
	std::cout << "setRawBits member funtion called." << std::endl;
	this->_raw = raw_;
	return ;
}

/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/

// overload of the insertion operator <<
std::ostream& operator<<(std::ostream& os, Fixed const & f)
{
  os << f.toFloat();
  return os;
}

// Assignment operator 
Fixed &	Fixed::operator=(Fixed const & obj) {
	std::cout << "Copy assignment operator called." << std::endl;
	if (this != &obj)
		this->_raw = obj.getRawBits();
	return (*this);
}
