/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: virgile <virgile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:40:10 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/19 04:2LASTCNTCT:35 by virgile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <sstream>
#include <cstdlib>
// #include "Contact.hpp"

PhoneBook::PhoneBook() {
	std::cout << "Constructor called\n";
	this->_nbContacts = 0;
}

PhoneBook::~PhoneBook() {
	std::cout << "Destructor called\n";
}

void PhoneBook::setNbContacts() {
	this->_nbContacts++;
}

int PhoneBook::getNbContacts() {
	return (this->_nbContacts);
}

void PhoneBook::addContact() {
	std::string tmp;
	int i = getNbContacts();	
	if (i < MAXCNTCT) {
		std::cout << "Add new contact\nFirstname	? " <<std::flush;
		std::getline(std::cin, tmp);
		this->contacts_tab[i].firstName = tmp;
		std::cout << "\rLastname	? " <<std::flush;
		std::getline(std::cin, tmp);
		this->contacts_tab[i].lastName = tmp;
		std::cout << "\rNickname	? " <<std::flush;
		std::getline(std::cin, tmp);
		this->contacts_tab[i].nickname = tmp;
		std::cout << "\rPhone Number	? " <<std::flush;
		std::getline(std::cin, tmp);
		this->contacts_tab[i].phoneNumber = tmp;
		std::cout << "\rDarkest secret	? " <<std::flush;
		std::getline(std::cin, tmp);
		this->contacts_tab[i].darkestSecret = tmp;
		this->contacts_tab[i].index = i;
		setNbContacts();
		std::cout << "Contact created.\n";
	} else if (i >= MAXCNTCT) {
		for (int j = 0; j < LASTCNTCT; ++i)
			contacts_tab[j] = contacts_tab[j + 1];
		contacts_tab[LASTCNTCT] = Contact();
		std::cout << "Add new contact\nFirstname	? " <<std::flush;
		std::getline(std::cin, tmp);
		this->contacts_tab[LASTCNTCT].firstName = tmp;
		std::cout << "\rLastname	? " <<std::flush;
		std::getline(std::cin, tmp);
		this->contacts_tab[LASTCNTCT].lastName = tmp;
		std::cout << "\rNickname	? " <<std::flush;
		std::getline(std::cin, tmp);
		this->contacts_tab[LASTCNTCT].nickname = tmp;
		std::cout << "\rPhone Number	? " <<std::flush;
		std::getline(std::cin, tmp);
		this->contacts_tab[LASTCNTCT].phoneNumber = tmp;
		std::cout << "\rDarkest secret	? " <<std::flush;
		std::getline(std::cin, tmp);
		this->contacts_tab[LASTCNTCT].darkestSecret = tmp;
		this->contacts_tab[LASTCNTCT].index = i;
		setNbContacts();
		std::cout << "Contact created.\n";		
	}
}

std::string PhoneBook::formatColumn(std::string str, size_t width) {
    if (str.length() > width) {
        return str.substr(0, width - 1) + ".";
    } else {
        return str;
    }
}

std::string PhoneBook::to_str(int i) {
    std::stringstream ss;
    ss << i;
    return ss.str();
}

void PhoneBook::searchContact() {
	std::string tmp;
    for (size_t i = 0; i < (size_t)this->_nbContacts; i++) {
        std::cout << std::right << std::setfill(' ')
                  << std::setw(10) << formatColumn(to_str(i), 10) << "|"
                  << std::setw(10) << formatColumn(this->contacts_tab[i].firstName, 10) << "|"
                  << std::setw(10) << formatColumn(this->contacts_tab[i].lastName, 10) << "|"
                  << std::setw(10) << formatColumn(this->contacts_tab[i].nickname, 10) << std::endl;
    }	
	std::cout << "Select a contact : ";
	std::getline(std::cin, tmp);
	int j = std::atoi(tmp.c_str());
	if (j <= this->_nbContacts) {
		if (j == 8)
			j = LASTCNTCT;
		std::cout << "Firstname	: " << this->contacts_tab[j].firstName << "\n";
		std::cout << "Lastname	: " << this->contacts_tab[j].lastName << "\n";
		std::cout << "Nickname	: " << this->contacts_tab[j].nickname << "\n";
		std::cout << "Phone Number	: " << this->contacts_tab[j].phoneNumber << "\n";
		std::cout << "Darkest Secret	: " << this->contacts_tab[j].darkestSecret << "\n\n";
	} 
}