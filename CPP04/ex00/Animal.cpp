/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:02:05 by vtestut           #+#    #+#             */
/*   Updated: 2024/03/19 20:10:32 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/******************************************************************************/
/*								PUBLIC										  */
/******************************************************************************/

void Animal::makeSound() const { std::cout << ".............. o_O" << std::endl; }

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

Animal::Animal(void) : _type("Animal") {
	std::cout << CYAN "Animal constructed" RESET << std::endl;
}

Animal::Animal(const Animal & obj) : _type(obj._type) {
	std::cout << CYAN "Animal constructed" RESET << std::endl;
}

Animal::~Animal(void) {
	std::cout << RED "Animal destructed" RESET << std::endl;
}

/******************************************************************************/
/*								ACCESSORS									  */
/******************************************************************************/

std::string Animal::getType() const { return (this->_type); }

/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/

Animal & Animal::operator=(const Animal & obj) {
	if (this != &obj)
		this->_type = obj._type;
	return (*this);
}
