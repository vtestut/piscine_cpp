/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:41:36 by vtestut           #+#    #+#             */
/*   Updated: 2024/03/04 21:07:25 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

#define PRINT_MESSAGE 0
/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

Fixed::Fixed( void ) : _raw( 0 )
{
	if ( PRINT_MESSAGE == 1 )
		std::cerr << CYAN "Default constructor called." RESET << std::endl;
	return ;
}

Fixed::Fixed( Fixed const & src )
{
	if ( PRINT_MESSAGE == 1 )
		std::cerr << CYAN "Copy constructor called." RESET << std::endl;
	*this = src;
	return ;
}

Fixed::Fixed( int const n ) : _raw( n << _Bits )
{
	if ( PRINT_MESSAGE == 1 )
		std::cerr << CYAN "Int constructor called." RESET << std::endl;
	return ;
}

Fixed::Fixed( float const f ) : _raw( roundf(f * (1 << _Bits)) )
{
	if ( PRINT_MESSAGE == 1 )
		std::cerr << CYAN "Float constructor called." RESET << std::endl;
	return ;
}

Fixed::~Fixed( void )
{
	if ( PRINT_MESSAGE == 1 )
		std::cerr << CYAN "Destructor called." RESET << std::endl;
	return ;
}

/******************************************************************************/
/*								OPERATORS								  	  */
/******************************************************************************/

Fixed &	Fixed::operator=( Fixed const & src )
{
	if ( PRINT_MESSAGE == 1 )
		std::cerr << YELLOW "Copy assignment operator called." RESET << std::endl;
	if ( this != &src )
		this->_raw = src.getRawBits();
	return ( *this );
}

bool	Fixed::operator>( Fixed const & rhs ) const
{
	// TODO for repush: can simply
	//	return ( this->_raw > rhs.getRawBits() );
	if ( this->_raw > rhs.getRawBits() )
		return ( true );
	return ( false );
}

bool	Fixed::operator<( Fixed const & rhs ) const
{
	if ( this->_raw < rhs.getRawBits() )
		return ( true );
	return ( false );
}

bool	Fixed::operator>=( Fixed const & rhs ) const
{
	if ( this->_raw >= rhs.getRawBits() )
		return ( true );
	return ( false );
}

bool	Fixed::operator<=( Fixed const & rhs ) const
{
	if ( this->_raw <= rhs.getRawBits() )
		return ( true );
	return ( false );
}

bool	Fixed::operator==( Fixed const & rhs ) const
{
	if ( this->_raw == rhs.getRawBits() )
		return ( true );
	return ( false );
}

bool	Fixed::operator!=( Fixed const & rhs ) const
{
	if ( this->_raw != rhs.getRawBits() )
		return ( true );
	return ( false );
}

Fixed	Fixed::operator+( Fixed const & rhs ) const
{
	return ( Fixed( this->toFloat() + rhs.toFloat() ) );
}

Fixed	Fixed::operator-( Fixed const & rhs ) const
{
	return ( Fixed( this->toFloat() - rhs.toFloat() ) );
}

Fixed	Fixed::operator*( Fixed const & rhs ) const
{
	return ( Fixed( this->toFloat() * rhs.toFloat() ) );
}

Fixed	Fixed::operator/( Fixed const & rhs ) const
{
	return ( Fixed( this->toFloat() / rhs.toFloat() ) );
}

Fixed &	Fixed::operator++( void ) // Prefix, i.e. ++fixed
{
	this->_raw += 1;
	return ( *this );
}

Fixed Fixed::operator++( int ) // Postfix, i.e. fixed++
{
	Fixed	tmp( *this );

	++(*this);
	return ( tmp );
}

Fixed &	Fixed::operator--( void ) // Prefix, i.e. --fixed
{
	this->_raw -= 1;
	return ( *this );
}

Fixed Fixed::operator--( int ) // Postfix, i.e. fixed--
{
	Fixed	tmp( *this );

	--(*this);
	return ( tmp );
}

/******************************************************************************/
/*								GETTERS										  */
/******************************************************************************/
int	Fixed::getRawBits( void ) const
{
	if ( PRINT_MESSAGE == 1 )
		std::cerr << GREEN "getRawBits member function called." RESET << std::endl;
	return ( this->_raw );
}

/******************************************************************************/
/*								SETTERS										  */
/******************************************************************************/
void	Fixed::setRawBits( int const raw )
{
	if ( PRINT_MESSAGE == 1 )
		std::cerr << GREEN "setRawBits member funtion called." RESET << std::endl;
	this->_raw = raw;
	return ;
}

/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/
int		Fixed::toInt( void ) const
{
	return ( this->_raw >> Fixed::_Bits );	
}

float	Fixed::toFloat( void ) const
{
	return ( (float)this->_raw / (1 << _Bits) );
}

Fixed &	Fixed::min( Fixed & lhs, Fixed & rhs )
{
	if ( lhs <= rhs )
		return ( lhs );
	return ( rhs );
}

Fixed const &	Fixed::min( Fixed const & lhs, Fixed const & rhs )
{
	if ( lhs <= rhs )
		return ( lhs );
	return ( rhs );
}

Fixed &	Fixed::max( Fixed & lhs, Fixed & rhs )
{
	if ( lhs >= rhs )
		return ( lhs );
	return ( rhs );
}

Fixed const &	Fixed::max( Fixed const & lhs, Fixed const & rhs )
{
	if ( lhs >= rhs )
		return ( lhs );
	return ( rhs );
}

std::ostream& operator<<( std::ostream& os, const Fixed& number )
{
	os << number.toFloat();
	return ( os );
}


// /******************************************************************************/
// /*								PUBLIC										  */
// /******************************************************************************/


// int Fixed::getRawBits(void) const {
// 	return this->_raw;
//   std::cout << "getRawBits member function called" <<std::endl;
// }

// void Fixed::setRawBits(int const raw_) {
// 	this->_raw = raw_;
// }

// float Fixed::toFloat(void) const {
// 	return roundf(this->_raw / 256) + ((this->_raw % 256)) / 256.0;
// }

// int Fixed::toInt(void) const {
// 	return roundf(this->_raw / 256.0);
// }


// /******************************************************************************/
// /*						CONSTRUCTORS & DESTRUCTORS							  */
// /******************************************************************************/


// //	Default Constructor
// Fixed::Fixed(void) {
// 	this->_raw = 0;
// 	std::cout << "Default constructor called" <<std::endl;
// }

// //	Parametric Constructor
// Fixed::Fixed(int const p1) : _raw(p1 * 256) {}

// //	Parametric Constructor
// Fixed::Fixed(float const p1) {
// 	int	raw_int = (int)(p1);
// 	int raw_dec = roundf((p1 - (int)p1) * 256);
// 	this->_raw = raw_int * 256 * raw_dec;
// }

// //	Copy constructor
// Fixed::Fixed(Fixed const & src) {
// 	*this = src;
// 	std::cout << "Copy constructor called" <<std::endl;
// }
	
// //	Default Destructor
// Fixed::~Fixed(void) {}


// /******************************************************************************/
// /*							OPERATOR OVERLOAD								  */
// /******************************************************************************/

// // an already initialized object is assigned to a new value from another existing object
// // copy assignment operator overload
// Fixed& Fixed::operator = (Fixed const &obj) {
//   if (this != &obj)
//     this->_raw = obj.getRawBits();
//   return (*this);
// }

// bool  Fixed::operator == (const Fixed &refOther ) const {
//   return this->getRawBits() == refOther.getRawBits();
// }

// bool  Fixed::operator != (const Fixed &refOther) const {
//   return this->getRawBits() != refOther.getRawBits();
// }

// bool  Fixed::operator >  (const Fixed &refOther) const {
//   return this->getRawBits() > refOther.getRawBits();
// }

// bool  Fixed::operator >= (const Fixed &refOther) const {
//   return this->getRawBits() >= refOther.getRawBits();
// }

// bool  Fixed::operator < (const Fixed &refOther) const {
//   return this->getRawBits() < refOther.getRawBits();
// }

// bool  Fixed::operator <= (const Fixed &refOther) const {
//   return this->getRawBits() <= refOther.getRawBits();
// }

// Fixed  Fixed::operator + (const Fixed &refOther) const {
//   return Fixed(this->toFloat() + refOther.toFloat());
// }

// Fixed  Fixed::operator - (const Fixed &refOther) const {
//   return Fixed(this->toFloat() - refOther.toFloat());
// }

// Fixed  Fixed::operator * (const Fixed &refOther) const {
//   return Fixed(this->toFloat() * refOther.toFloat());
// }

// Fixed  Fixed::operator / (const Fixed &refOther) const {
//   return Fixed(this->toFloat() / refOther.toFloat());
// }

// Fixed  Fixed::operator ++ (int) { // a++
//   Fixed tmp(*this);
//   tmp._raw = (this->_raw)++;
//   return tmp;
// }

// Fixed& Fixed::operator ++ (void) { // ++a
//   ++(this->_raw);
//   return *this;
// }

// Fixed  Fixed::operator -- (int) {
//   Fixed tmp(*this);
//   tmp._raw = (this->_raw)--;
//   return tmp;
// }

// Fixed& Fixed::operator -- (void) {
//   --(this->_raw);
//   return *this;
// }

// Fixed& Fixed::max (Fixed &ref1, Fixed &ref2) {
//   if (ref1.toFloat() >= ref2.toFloat())
//     return ref1;    
//   return ref2;
// }

// Fixed& Fixed::max (const Fixed &ref1, const Fixed &ref2) {
//   if (ref1.toFloat() >= ref2.toFloat())
//     return (Fixed&)ref1;
//   return (Fixed&)ref2;
// }

// Fixed& Fixed::min (Fixed &ref1, Fixed &ref2) {
//   if (ref1.toFloat() <= ref2.toFloat())
//     return ref1;    
//   return ref2;
// }

// Fixed& Fixed::min (const Fixed &ref1, const Fixed &ref2) {
//   if (ref1.toFloat() <= ref2.toFloat())
//     return (Fixed&)ref1;
//   return (Fixed&)ref2;
// }


// /******************************************************************************/
// /*							GLOBAL FUNCTIONS								  */
// /******************************************************************************/

// std::ostream& operator<<(std::ostream & ofs, Fixed const & i)
// {
// 	ofs << i.toFloat();
// 	return ofs;
// }
