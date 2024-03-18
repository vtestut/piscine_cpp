/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:20:38 by vtestut           #+#    #+#             */
/*   Updated: 2024/03/18 18:03:34 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	 _FIXED_HPP
# define _FIXED_HPP

# include <iostream>
# include <cmath>

# define FIXED_BITS 8

class Fixed {

private:
	
		int _value;
		static const int _bits = 8;
	
public:
	
		Fixed();									// Canonical
		Fixed(const Fixed & obj);					// Canonical
		Fixed(const int n);
		Fixed(const float n);
		
		~Fixed();									// Canonical

		int		getRawBits(void) const;
		void	setRawBits(const int raw);
		
		float	toFloat(void) const;
		int		toInt(void) const;

		static Fixed &			min(Fixed & a, Fixed & b);
		static Fixed &			max(Fixed & a, Fixed & b);
		static const Fixed &	min(const Fixed & a, const Fixed & b);
		static const Fixed &	max(const Fixed & a, const Fixed & b);

		//	arithmetic operators
		Fixed &	operator=(const Fixed & obj);		// Canonical
		Fixed	operator+(const Fixed & rhs);
		Fixed	operator-(const Fixed & rhs);
		Fixed	operator*(const Fixed & rhs);
		Fixed	operator/(const Fixed & rhs);

		//	Pre/De-crementation operators 
		Fixed &	operator++(void); //			++i		pre incrementation
		Fixed &	operator--(void); //			--i		pre decrementation
		Fixed	operator++(int);	
		Fixed	operator--(int);

		// comparison operators
		bool	operator>(const Fixed & rhs) const;
		bool	operator<(const Fixed & rhs) const;
		bool	operator>=(const Fixed & rhs) const;
		bool	operator<=(const Fixed & rhs) const;
		bool	operator==(const Fixed & rhs) const;
		bool	operator!=(const Fixed & rhs) const;
};

std::ostream & operator<<(std::ostream & os, const Fixed & n);

#endif
