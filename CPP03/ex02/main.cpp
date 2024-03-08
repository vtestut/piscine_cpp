/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:30:13 by vtestut           #+#    #+#             */
/*   Updated: 2024/03/08 20:46:05 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

// ! modifier berepaired et take damage dans les previous exo

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
	c.attack(b.getName());
	c.takeDamage(10);
	c.beRepaired(-100000);
	c.highFivesGuys();
	std::cout << std::endl;

	return (0);
}
