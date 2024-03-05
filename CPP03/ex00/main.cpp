/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:43:14 by vtestut           #+#    #+#             */
/*   Updated: 2024/03/05 21:26:17 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//int argc, char **argv
int main()
{
	std::cout << CYAN "Tests for default constructor :" RESET << std::endl;
	ClapTrap a;
	std::cout << "Name\t= " << a.getName() << std::endl;
	std::cout << "Hit\t= " << a.getHitPoints() << std::endl;
	std::cout << "Energy\t= " << a.getEnergyPoints() << std::endl;
	std::cout << "Attack\t= " << a.getAttackPoints() << std::endl;
	std::cout << std::endl;
	
	std::cout << CYAN "Tests for copy constructor :" RESET << std::endl;
	ClapTrap b(a);
	std::cout << "Name\t= " << b.getName() << std::endl;
	std::cout << "Hit\t= " << b.getHitPoints() << std::endl;
	std::cout << "Energy\t= " << b.getEnergyPoints() << std::endl;
	std::cout << "Attack\t= " << b.getAttackPoints() << std::endl;
	std::cout << std::endl;
	
	std::cout << CYAN "Tests for copy constructor :" RESET << std::endl;
	
	return (0);
}