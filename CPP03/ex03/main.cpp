/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 20:31:16 by vtestut           #+#    #+#             */
/*   Updated: 2024/03/18 19:30:05 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	std::cout << std::endl;
	std::cout << CYAN "Test for ScavTrap :" RESET << std::endl;
	ScavTrap a("SCAVTRAP_01");
	a.attack("TARGET");
	a.takeDamage(20);
	a.beRepaired(20);
	a.guardGate();

	std::cout << std::endl;
	std::cout << CYAN "Test for FragTrap :" RESET << std::endl;
	FragTrap b("FRAGTRAP_01");
	b.attack("TARGET");
	b.takeDamage(20);
	b.beRepaired(20);
	b.highFivesGuys();
	
	std::cout << std::endl;
	std::cout << CYAN "Test for DiamondTrap :" RESET << std::endl;
	DiamondTrap c("DIAMONDTRAP_01");
	c.attack("TARGET");
	c.takeDamage(20);
	c.beRepaired(20);
	c.guardGate();
	c.highFivesGuys();
	c.whoAmI();
	
	return (0);
}