/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:13:24 by vtestut           #+#    #+#             */
/*   Updated: 2024/03/19 20:16:27 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/******************************************************************************/
/*								PUBLIC										  */
/******************************************************************************/

void Dog::makeSound() const { std::cout << "ouaf ouaf" << std::endl; }

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

Dog::Dog(void) {
	this->_type = "Dog";
	std::cout << CYAN "Dog constructed" RESET << std::endl;
}

Dog::Dog(const Dog& obj) {
	this->_type = obj._type;
	std::cout << CYAN "Dog constructed" RESET << std::endl;
}

Dog::~Dog(void) { std::cout << RED "Dog destructed" RESET << std::endl; }

/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/

Dog & Dog::operator=(const Dog & obj) {
	if (this != &obj)
		this->_type = obj._type;
	return (*this);
}
