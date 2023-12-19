/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:39:56 by vtestut           #+#    #+#             */
/*   Updated: 2023/12/19 19:39:57 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact(void) : firstName(""),
						 lastName(""),
						 nickname(""),
						 phoneNumber(""),
						 darkestSecret("")
{
	return;
}

Contact::~Contact(void)
{
	return;
}

std::string Contact::getFirstName(void) const
{
	return this->firstName;
}

void Contact::setFirstName(std::string firstName)
{
	this->firstName = firstName;

	return;
}

std::string Contact::getLastName(void) const
{
	return this->lastName;
}

void Contact::setLastName(std::string lastName)
{
	this->lastName = lastName;

	return;
}

std::string Contact::getNickname(void) const
{
	return this->nickname;
}

void Contact::setNickname(std::string nickname)
{
	this->nickname = nickname;

	return;
}

std::string Contact::getPhoneNumber(void) const
{
	return this->phoneNumber;
}

void Contact::setPhoneNumber(std::string phoneNumber)
{
	this->phoneNumber = phoneNumber;

	return;
}