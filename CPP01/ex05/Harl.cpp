/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:07:07 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/24 21:06:43 by vtestut          ###   ########.fr       */
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

	funcPtr[0] = &Harl::debug;
	funcPtr[1] = &Harl::info;
	funcPtr[2] = &Harl::warning;
	funcPtr[3] = &Harl::error;

	for (int i = 0; i < 4; i++)
		if (messages[i] == level)
			(this->*funcPtr[i])();
}

void Harl::debug() {
	std::cout << DEBUG << std::endl;
}

void Harl::warning() {
	std::cout << WARN << std::endl;
}

void Harl::info() {
	std::cout << INFO << std::endl;
}

void Harl::error() {
	std::cout << ERROR << std::endl;
}