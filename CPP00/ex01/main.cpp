/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: virgile <virgile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:49:09 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/19 03:45:46 by virgile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

/*
	- Les champs d'un contact ne peuvent etre vide
	- 
*/
int main()
{
	PhoneBook book;
	std::string userInput;
	
	while (1)
	{
		std::cout << "Enter ADD, SEARCH or EXIT\n";
		std::getline(std::cin, userInput);
		
		if (userInput == "ADD") {
			book.addContact();
		} else if (userInput == "SEARCH") {
			std::cout << "Print PhoneBook\n";
			book.searchContact();
		} else if (userInput == "EXIT") {
			return (1);
		} else
			std::cout << "Command not found\n";
	}
	
	return 0;
}