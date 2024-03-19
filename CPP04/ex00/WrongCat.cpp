/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:34:42 by vtestut           #+#    #+#             */
/*   Updated: 2024/03/19 20:41:08 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/******************************************************************************/
/*								PUBLIC										  */
/******************************************************************************/

void WrongCat::makeSound() const { std::cout << "puke puke" << std::endl; }

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

WrongCat::WrongCat(void) {
	this->_type = "WrongCat";
	std::cout << CYAN "WrongCat constructed" RESET << std::endl;
}


WrongCat::WrongCat(const WrongCat & obj) {
	this->_type = obj._type;
	std::cout << CYAN "WrongCat constructed" RESET << std::endl;
}

WrongCat::~WrongCat(void) {
	std::cout << RED "WrongCat destructed." RESET << std::endl;
}

/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/

WrongCat & WrongCat::operator=(const WrongCat & obj) {
	if (this != &obj)
		this->_type = obj._type;
	return (*this);
}
