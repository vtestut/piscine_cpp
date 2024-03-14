/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:43:14 by vtestut           #+#    #+#             */
/*   Updated: 2024/03/14 16:36:19 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	std::cout << CYAN "Test for default constructor :" RESET << std::endl;
	ClapTrap a;
	std::cout << "Name\t= " << a.getName() << std::endl;
	std::cout << "Hit\t= " << a.getHitPoints() << std::endl;
	std::cout << "Energy\t= " << a.getEnergyPoints() << std::endl;
	std::cout << "Attack\t= " << a.getAttackPoints() << std::endl;
	std::cout << std::endl;
	
	std::cout << CYAN "Test for parametric constructor :" RESET << std::endl;
	ClapTrap b("RATTATAC");
	std::cout << "Name\t= " << b.getName() << std::endl;
	std::cout << "Hit\t= " << b.getHitPoints() << std::endl;
	std::cout << "Energy\t= " << b.getEnergyPoints() << std::endl;
	std::cout << "Attack\t= " << b.getAttackPoints() << std::endl;
	std::cout << std::endl;
	
	std::cout << CYAN "Tests for copy constructor :" RESET << std::endl;
	ClapTrap c(b);
	std::cout << "Name\t= " << c.getName() << std::endl;
	std::cout << "Hit\t= " << c.getHitPoints() << std::endl;
	std::cout << "Energy\t= " << c.getEnergyPoints() << std::endl;
	std::cout << "Attack\t= " << c.getAttackPoints() << std::endl;
	std::cout << std::endl;

	std::cout << CYAN "Tests for assignment constructor :" RESET << std::endl;
	ClapTrap d;
	d = c;
	std::cout << "Name\t= " << d.getName() << std::endl;
	std::cout << "Hit\t= " << d.getHitPoints() << std::endl;
	std::cout << "Energy\t= " << d.getEnergyPoints() << std::endl;
	std::cout << "Attack\t= " << d.getAttackPoints() << std::endl;
	std::cout << std::endl;

	std::cout << CYAN "Tests for actions :" RESET << std::endl;
	ClapTrap e("MAGICARPE");
	while (e.getEnergyPoints() != 0 && e.getHitPoints() != 0)
	{
		d.attack(e.getName());
		if (d.getEnergyPoints() > 0) 
			e.takeDamage(d.getAttackPoints());
		e.beRepaired(d.getAttackPoints());
		if (d.getEnergyPoints() <= 0) {
			std::cout << CYAN << d.getName() << " USE OIL MAX. Its energy points are restored" RESET << std::endl;
			d.setEnergyPoints(10);
		}
	}
	d.attack(e.getName());
	e.takeDamage(d.getAttackPoints());
	e.beRepaired(2);
	
	std::cout << std::endl;	
	std::cout << "Name\t= " << d.getName() << std::endl;
	std::cout << "Hit\t= " << d.getHitPoints() << std::endl;
	std::cout << "Energy\t= " << d.getEnergyPoints() << std::endl;
	std::cout << "Attack\t= " << d.getAttackPoints() << std::endl;
	std::cout << std::endl;	

	std::cout << "Name\t= " << e.getName() << std::endl;
	std::cout << "Hit\t= " << e.getHitPoints() << std::endl;
	std::cout << "Energy\t= " << e.getEnergyPoints() << std::endl;
	std::cout << "Attack\t= " << e.getAttackPoints() << std::endl;
	std::cout << std::endl;
	
	return (0);
}