/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:10:20 by vtestut           #+#    #+#             */
/*   Updated: 2024/03/04 20:30:30 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  _FIXED_HPP
# define _FIXED_HPP

# include <iostream>
# include <cmath>

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

class Fixed {

private:

		int	_raw;									// fixed-point number value
		static const int _bits = 8;					// number of fractional bits

public:

		Fixed(void);								// Canonical
		Fixed(Fixed const & obj);					// Canonical
		Fixed(const int raw_);						// NEW converts p to the corresponding fpv, n is initialized to 8
		Fixed(const float raw_);					// NEW converts p to the corresponding fpv, n is initialized to 8
		~Fixed();									// Canonical

		int		getRawBits(void) const;
		void	setRawBits(const int raw_);
		float	toFloat(void) const;       			// NEW converts the fixed-point value to a floating-point value
		int		toInt(void) const;         			// NEW converts the fixed-point value to an integer value
		
		Fixed &	operator=(const Fixed & obj);		// Canonical
};

/******************************************************************************/
/*								PROTOTYPES									  */
/******************************************************************************/

std::ostream&      operator<<(std::ostream& os, Fixed const & f); // NEW overload of the insertion operator <<, inserts a floating-p representation of the fp number into the output stream object passed as param

#endif