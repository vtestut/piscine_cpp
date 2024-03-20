/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:19:15 by vtestut           #+#    #+#             */
/*   Updated: 2024/03/20 16:58:26 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/******************************************************************************/
/*								PUBLIC										  */
/******************************************************************************/

void Cat::makeSound() const { std::cout << "miaou miaou" << std::endl; }

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

Cat::Cat(void) : Animal(), _brain(new Brain()) {
	std::cout << CYAN "Cat constructed" RESET << std::endl;
	this->_type = "Cat";
}

Cat::Cat(const Cat& obj) {
	this->_type = obj._type;
	std::cout << CYAN "Cat constructed" RESET << std::endl;
}

Cat::~Cat(void) { std::cout << RED "Cat destructed" RESET << std::endl; }

/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/

Cat & Cat::operator=(const Cat & obj) {
	if (this != &obj)
		this->_type = obj._type;
	return (*this);
}