#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <cstdlib>

static bool catchInput(std::string display, std::string *line) {
	std::cout << display;
	if (std::cin.eof())
		return false;
	if (!std::getline(std::cin, *line))
		return false;
	return true;
}

int main() {
	std::cout << "\nWelcome to Phone Book\n";
	PhoneBook phonebook;
	while (1 && !std::cin.eof()) {
		std::string usrInput;
		if (!catchInput("\nType ADD, SEARCH or EXIT : ", &usrInput)
		|| usrInput == "EXIT"
		|| usrInput == "exit")
			break;
		else if (usrInput == "ADD" || usrInput == "add") {
			Contact contact;
			std::cout << "\nAdd a new contact\n\n";
			if (catchInput("First name\t: ", &contact.firstName)
			&& catchInput("Last name\t: ", &contact.lastName)
			&& catchInput("Nickname\t: ", &contact.nickName)
			&& catchInput("Phone number\t: ", &contact.phoneNumber)
			&& catchInput("Darkest secret\t: ", &contact.darkestSecret)) {
				std::cout << std::endl;
				phonebook.addContact(contact);
			}
		} else if (usrInput == "SEARCH" || usrInput == "search") {
			std::string str_index;
			if (phonebook.showAll())
				if(catchInput("Enter index to show details : ", &str_index))
					phonebook.showContact(str_index);
		} else
			std::cout << "\nCommand not found\n";
	}
	std::cout << "\n\nExit Phone Book\n\n";
	return (0);
}