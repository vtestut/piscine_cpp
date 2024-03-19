/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:29:34 by vtestut           #+#    #+#             */
/*   Updated: 2024/03/19 20:41:03 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/******************************************************************************/
/*								PUBLIC										  */
/******************************************************************************/

void WrongAnimal::makeSound() const { std::cout << "Wrong Animal Noise" << std::endl; }

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

WrongAnimal::WrongAnimal(void): _type("WrongAnimal") {
	std::cout << CYAN "WrongAnimal constructed" RESET << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & obj) : _type(obj._type) {
	std::cout << CYAN "WrongAnimal constructed." RESET << std::endl;
}

WrongAnimal::~WrongAnimal(void) { 
	std::cout << RED "WrongAnimal destructed." RESET << std::endl;
}

/******************************************************************************/
/*							GETTERS & SETTERS								  */
/******************************************************************************/

std::string WrongAnimal::getType() const { return (this->_type); }

/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/


WrongAnimal & WrongAnimal::operator=(const WrongAnimal & obj) {
	if (this != &obj)
		this->_type = obj._type;
	return (*this);
}
