/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v <v@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:07:10 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/25 01:31:36 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <iostream>

# define RESET	"\033[0m" 
# define RED	"\033[31m"
# define CYAN	"\033[34m"
# define YELLOW	"\033[93m"

# define DEBUG	"[ DEBUG ]\nReprend du café ca va aller\n"
# define INFO	"[ INFO ]\nLes loutres gardent leur petit cailloux favoris dans une poche sous leur bras\n"
# define WARN	"[ WARNING ]\nWOOP WOOOOOP WOOOOOOOOP\n"
# define ERROR	"[ ERROR ]\nQu'on lui couuuuuupe la tete !"

class Harl {

	public: 

		void complain(std::string level);
		
	private:
		
		void _debug(void);
		void _info(void);
		void _warning(void);
		void _error(void);
};

#endif
