/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:30:13 by vtestut           #+#    #+#             */
/*   Updated: 2024/03/14 18:31:51 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	std::cout << CYAN "Test for FragTrap parametric constructor :" RESET << std::endl;
	FragTrap a("BULBIZARRE");
	std::cout << "Name\t= " << a.getName() << std::endl;
	std::cout << "Hit\t= " << a.getHitPoints() << std::endl;
	std::cout << "Energy\t= " << a.getEnergyPoints() << std::endl;
	std::cout << "Attack\t= " << a.getAttackPoints() << std::endl;
	std::cout << std::endl;

	std::cout << CYAN "Tests for FragTrap copy constructor :" RESET << std::endl;
	FragTrap b(a);
	std::cout << "Name\t= " << b.getName() << std::endl;
	std::cout << "Hit\t= " << b.getHitPoints() << std::endl;
	std::cout << "Energy\t= " << b.getEnergyPoints() << std::endl;
	std::cout << "Attack\t= " << b.getAttackPoints() << std::endl;
	std::cout << std::endl;

	std::cout << CYAN "Tests for FragTrap assignment constructor :" RESET << std::endl;
	FragTrap c;
	c = b;
	std::cout << "Name\t= " << c.getName() << std::endl;
	std::cout << "Hit\t= " << c.getHitPoints() << std::endl;
	std::cout << "Energy\t= " << c.getEnergyPoints() << std::endl;
	std::cout << "Attack\t= " << c.getAttackPoints() << std::endl;
	std::cout << std::endl;
	
	std::cout << CYAN "Tests for actions :" RESET << std::endl;
	FragTrap d("CARAPUCE");
	while(a.getEnergyPoints() != 0 && d.getHitPoints() != 0)
	{
		a.attack(d.getName());
		if (a.getEnergyPoints() >= 0)
			d.takeDamage(a.getAttackPoints());
	}
	d.beRepaired(20);
	d.attack(a.getName());
	a.highFivesGuys();

	std::cout << std::endl;
	std::cout << "Name\t= " << a.getName() << std::endl;
	std::cout << "Hit\t= " << a.getHitPoints() << std::endl;
	std::cout << "Energy\t= " << a.getEnergyPoints() << std::endl;
	std::cout << "Attack\t= " << a.getAttackPoints() << std::endl;

	std::cout << std::endl;
	std::cout << "Name\t= " << d.getName() << std::endl;
	std::cout << "Hit\t= " << d.getHitPoints() << std::endl;
	std::cout << "Energy\t= " << d.getEnergyPoints() << std::endl;
	std::cout << "Attack\t= " << d.getAttackPoints() << std::endl;
	std::cout << std::endl;

	return (0);
}
