#include "phonebook.hpp"
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
	std::cout << "\n\nWelcome to phonebook\n\n";
	PhoneBook phonebook;
	while (1 && !std::cin.eof()) {
		std::string usrInput;
		if (!catchInput("Type ADD, SEARCH or EXIT : ", &usrInput) || 
		usrInput == "EXIT" || 
		usrInput == "exit")
			break;
		else if (usrInput == "ADD" || usrInput == "add") {
			Contact contact;
			std::cout << "\nAdd a new contact\n\n";
			if (catchInput("First name	: ", &contact.firstName) &&
			catchInput("Last name	: ", &contact.lastName) &&
			catchInput("Nickname	: ", &contact.nickName) &&
			catchInput("Phone number	: ", &contact.phoneNumber) &&
			catchInput("Darkest secret	: ", &contact.darkestSecret)) {
				std::cout << std::endl;
				phonebook.addContact(contact);
			}
		} else if (usrInput == "SEARCH" || usrInput == "search") {
			std::string str_index;
			if (phonebook.showAll())
				if(catchInput("Select a contact : ", &str_index) && isdigit(str_index[0]))
					phonebook.showContact(str_index);
		} else
			std::cout << "Command not found\n";
	}
	std::cout << "\n\nExit Phone Book\n\n";
	phonebook.clearContactsDeque();
	return (0);
}