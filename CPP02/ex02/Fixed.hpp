/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:20:38 by vtestut           #+#    #+#             */
/*   Updated: 2024/03/04 21:07:25 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	 _FIXED_HPP
# define _FIXED_HPP

# include <iostream>
# include <string>
# include <fstream>
// # include <map>
# include <cmath>
# include <climits>

/******************************************************************************/
/*									DEFINES									  */
/******************************************************************************/

# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define CYAN	"\033[36m"
# define YELLOW	"\033[93m"

# define RESET	"\033[0m"
# define CLEAR	"\033[2J\033[1;1H"

/******************************************************************************/
/*									CLASS									  */
/******************************************************************************/

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed & src);
		Fixed(const int n);
		Fixed(const float f);
		~Fixed();

		Fixed &	operator=(const Fixed & src);

		bool	operator>(const Fixed & rhs) const;
		bool	operator<(const Fixed & rhs) const;
		bool	operator>=(const Fixed & rhs) const;
		bool	operator<=(const Fixed & rhs) const;
		bool	operator==(const Fixed & rhs) const;
		bool	operator!=(const Fixed & rhs) const;

		Fixed	operator+(const Fixed & rhs) const;
		Fixed	operator-(const Fixed & rhs) const;
		Fixed	operator*(const Fixed & rhs) const;
		Fixed	operator/(const Fixed & rhs) const;

		Fixed &	operator++(void);
		Fixed	operator++(int);
		Fixed &	operator--(void);
		Fixed	operator--(int);

		int		getRawBits(void) const;
		void	setRawBits(const int raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		static Fixed &			min(Fixed & lhs, Fixed & rhs);
		static Fixed &			max(Fixed & lhs, Fixed & rhs);
		static const Fixed &	min(const Fixed & lhs, const Fixed & rhs);
		static const Fixed &	max(const Fixed & lhs, const Fixed & rhs);

	private:
		int					_raw;
		static const int	_Bits = 8;
};

/******************************************************************************/
/*									PROTOYPES								  */
/******************************************************************************/

std::ostream & operator<<(std::ostream & os, const Fixed & number);

#endif
