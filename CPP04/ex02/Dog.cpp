/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:17:38 by mcombeau          #+#    #+#             */
/*   Updated: 2024/03/20 16:54:11 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <string>
#include <iostream>

Dog::Dog(void) : Animal(), _brain(new Brain())
{
	std::cout << CYAN "Dog default constructor called." RESET << std::endl;
	this->_type = "Dog";
	return ;
}

Dog::Dog(Dog const & src) : Animal(), _brain(NULL)
{
	std::cout << CYAN "Dog copy constructor called." RESET << std::endl;
	*this = src;
	return ;
}

Dog::~Dog(void)
{
	std::cout << CYAN "Dog destructor called." RESET << std::endl;
	delete this->_brain;
	return ;
}

Dog &	Dog::operator=(Dog const & src)
{
	std::cout << GREEN "Dog assignment overload operator called." RESET << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
		if (this->_brain != NULL)
			delete this->_brain;
		this->_brain = new Brain(*src._brain);
	}
	return (*this);
}

Brain *	Dog::getBrain(void) const
{
	return (this->_brain);
}

void	Dog::makeSound(void) const
{
	std::cout << YELLOW << this->_type
		<< ": * Arf! Arf! Arf! *" RESET << std::endl;
	return ;
}
