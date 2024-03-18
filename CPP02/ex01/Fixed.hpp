/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:10:20 by vtestut           #+#    #+#             */
/*   Updated: 2024/03/18 17:50:37 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  _FIXED_HPP
# define _FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {

private:

		int	_value;
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
		
		Fixed &	operator=(const Fixed & obj);		// Canonical
};

std::ostream &	operator<<(std::ostream& os, const Fixed & n);

#endif
