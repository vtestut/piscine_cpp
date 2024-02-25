/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v <v@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:07:07 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/25 01:32:05 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::complain(std::string level) 
{
	void (Harl::*funcPtr[4])();
	
	std::string messages[] = 
	{	
		"debug", 
		"info",
		"warning",
		"error"
	};

	funcPtr[0] = &Harl::_debug;
	funcPtr[1] = &Harl::_info;
	funcPtr[2] = &Harl::_warning;
	funcPtr[3] = &Harl::_error;

	for (int i = 0; i < 4; i++)
		if (messages[i] == level)
			(this->*funcPtr[i])();
}

void Harl::_debug() {
	std::cout << DEBUG << std::endl;
}

void Harl::_info() {
	std::cout << CYAN << INFO << RESET << std::endl;
}

void Harl::_warning() {
	std::cout << YELLOW << WARN << RESET << std::endl;
}

void Harl::_error() {
	std::cout << RED << ERROR << RESET << std::endl;
}