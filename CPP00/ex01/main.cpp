#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <cstdlib>

static bool catchInput(std::string msg, std::string *line) {
	std::cout << CYAN << msg << RESET;
	if (std::cin.eof())
		return false;
	if (!std::getline(std::cin, *line))
		return false;
	return true;
}

int main() {
	PhoneBook phonebook;
	std::cout << CLEAR;
	while (1 && !std::cin.eof()) {
		std::string usrInput;
		if (!catchInput("\nType ADD, SEARCH or EXIT : ", &usrInput)
		|| usrInput == "EXIT" || usrInput == "exit")
			break;
		else if (usrInput == "ADD" || usrInput == "add") {
			Contact contact;
			std::cout << CYAN << CLEAR << "\nAdd a new contact\n\n";
			if (catchInput("First name\t: ", &contact.firstName)
			&& catchInput("Last name\t: ", &contact.lastName)
			&& catchInput("Nickname\t: ", &contact.nickName)
			&& catchInput("Phone number\t: ", &contact.phoneNumber)
			&& catchInput("Darkest secret\t: ", &contact.darkestSecret)) {
				std::cout << CLEAR;
				phonebook.addContact(contact);
			}
		} else if (usrInput == "SEARCH" || usrInput == "search") {
			std::string str_index;
			if (phonebook.showAll()) {
				if(catchInput("Select index to show details : ", &str_index)) {
					std::cout << CYAN << CLEAR;
					phonebook.showContact(str_index);
				}
			}
		} else
			std::cout << RED << CLEAR << "\nCommand not found\n";
	}
	std::cout <<CLEAR << CYAN << "\nExit Phone Book ... \n\n" << RESET;
	return (0);
}