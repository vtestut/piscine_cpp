/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v <v@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 21:09:14 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/25 01:36:04 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::complain(std::string level) 
{	
	std::string levels[4] = 
	{	
		"debug", 
		"info",
		"warning",
		"error"
	};

	int i = -1;
	for (int j=0; j<4; j++){
		if ( levels[j] == level ){
			i = j;
			break ;
		}
	} switch (i) {
		case 0:
			this->_debug();
			i++;
		case 1:
			this->_info();
			i++;
		case 2:
			this->_warning();
			i++;
		case 3:
			this->_error();
			i++;
			break;
		default:
			std::cout << "complaining about something" << std::endl;	
	}
}

void Harl::_debug() {
	std::cout << DEBUG << std::endl;
}

void Harl::_info() {
	std::cout << CYAN << INFO<< RESET << std::endl;
}

void Harl::_warning() {
	std::cout << YELLOW << WARN << RESET << std::endl;
}

void Harl::_error() {
	std::cout << RED << ERROR << RESET << std::endl;
}