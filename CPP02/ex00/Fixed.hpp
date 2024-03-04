/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:10:20 by vtestut           #+#    #+#             */
/*   Updated: 2024/03/04 18:51:42 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  _FIXED_HPP
# define _FIXED_HPP

# include <iostream>

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

		int	_raw;
		static const int _bits = 8;

public:

		Fixed(void);
		Fixed(const Fixed & obj);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(const int raw_);

		Fixed &	operator=(const Fixed & obj);

};

#endif
