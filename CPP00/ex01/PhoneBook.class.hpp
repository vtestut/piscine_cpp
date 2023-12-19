/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:39:45 by vtestut           #+#    #+#             */
/*   Updated: 2023/12/19 19:40:48 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PHONEBOOK_HPP__
#define __PHONEBOOK_HPP__

#include <iomanip>
#include <iostream>
#include <locale>
#include <string>
#include "Contact.class.hpp"

class PhoneBook
{
public:
	PhoneBook(void);
	~PhoneBook(void);

	bool addContact(void);
	void previewContacts(void) const;
	void showContactInformations(int index) const;

private:
	int oldestIndex;
	Contact contacts[8];

	Contact &wipeContact(int index);
	std::string getContactInfo(std::string const label) const;
	void showContactInfo(std::string const label,
						 std::string const info) const;
	std::string truncate(std::string const str) const;
};

#endif