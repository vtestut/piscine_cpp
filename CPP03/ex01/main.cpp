/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:46:41 by vtestut           #+#    #+#             */
/*   Updated: 2024/03/08 20:13:47 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	std::cout << CYAN "Test for ClapTrap parametric constructor :" RESET << std::endl;
	ClapTrap a("MAGICARP");
	std::cout << "Name\t= " << a.getName() << std::endl;
	std::cout << "Hit\t= " << a.getHitPoints() << std::endl;
	std::cout << "Energy\t= " << a.getEnergyPoints() << std::endl;
	std::cout << "Attack\t= " << a.getAttackPoints() << std::endl;
	std::cout << std::endl;

	std::cout << CYAN "Test for ScavTrap parametric constructor :" RESET << std::endl;
	ScavTrap b("SCAVTRAP");
	std::cout << "Name\t= " << b.getName() << std::endl;
	std::cout << "Hit\t= " << b.getHitPoints() << std::endl;
	std::cout << "Energy\t= " << b.getEnergyPoints() << std::endl;
	std::cout << "Attack\t= " << b.getAttackPoints() << std::endl;
	std::cout << std::endl;

	std::cout << CYAN "Tests for ScavTrap copy constructor :" RESET << std::endl;
	ScavTrap c(b);
	std::cout << "Name\t= " << c.getName() << std::endl;
	std::cout << "Hit\t= " << c.getHitPoints() << std::endl;
	std::cout << "Energy\t= " << c.getEnergyPoints() << std::endl;
	std::cout << "Attack\t= " << c.getAttackPoints() << std::endl;
	std::cout << std::endl;

	std::cout << CYAN "Tests for ScavTrap assignment constructor :" RESET << std::endl;
	ScavTrap d;
	d = c;
	std::cout << "Name\t= " << d.getName() << std::endl;
	std::cout << "Hit\t= " << d.getHitPoints() << std::endl;
	std::cout << "Energy\t= " << d.getEnergyPoints() << std::endl;
	std::cout << "Attack\t= " << d.getAttackPoints() << std::endl;
	std::cout << std::endl;

	std::cout << CYAN "Tests for actions :" RESET << std::endl;
	while(a.getEnergyPoints() != 0)
	{
		a.attack(d.getName());
		if (a.getEnergyPoints() >= 0)
			d.takeDamage(a.getAttackPoints());
	}
	d.beRepaired(20);
	d.attack(a.getName());
	a.takeDamage(d.getAttackPoints());
	while( d.getHitPoints() != 0)
	{
		d.attack("himself in confusion");
		d.takeDamage(d.getAttackPoints());
	}
	d.guardGate();
	
	std::cout << std::endl;
	std::cout << "Name\t= " << d.getName() << std::endl;
	std::cout << "Hit\t= " << d.getHitPoints() << std::endl;
	std::cout << "Energy\t= " << d.getEnergyPoints() << std::endl;
	std::cout << "Attack\t= " << d.getAttackPoints() << std::endl;
	std::cout << std::endl;

	std::cout << "Name\t= " << a.getName() << std::endl;
	std::cout << "Hit\t= " << a.getHitPoints() << std::endl;
	std::cout << "Energy\t= " << a.getEnergyPoints() << std::endl;
	std::cout << "Attack\t= " << a.getAttackPoints() << std::endl;
	std::cout << std::endl;

	return (0);
}