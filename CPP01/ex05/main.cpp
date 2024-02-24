/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:07:05 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/24 21:01:01 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main () 
{
	Harl Haaaarl;

	std::cout << std::endl;
	Haaaarl.complain("debug");
	std::cout << std::endl;
	Haaaarl.complain("info");
	std::cout << std::endl;
	Haaaarl.complain("warning");
	std::cout << std::endl;
	Haaaarl.complain("error");
	std::cout << std::endl;
	
	return (0);
}