#include "phonebook.hpp"
#include <cstdlib>

static bool catchInput(std::string display, std::string *line) {
	std::cout << display;
	if (std::cin.eof()) {
        std::cout << "EOF detected\n" <<std::flush << std::endl;
		exit(1);
    }
	if (!std::getline(std::cin, *line))
		return false;
	return true;
}

int main() {

	PhoneBook phonebook;
	std::cout << "Welcome to the 80's\n\n";
	std::string usrInput;
	while (1) {
		catchInput("Type ADD, SEARCH or EXIT : ", &usrInput);
		if (usrInput == "ADD" || usrInput == "add") {
			Contact contact;
			std::cout << "\nAdd a new contact\n\n";
			catchInput("First name	: ", &contact.firstName);
			catchInput("Last name	: ", &contact.lastName);
			catchInput("Nickname	: ", &contact.nickName);
			catchInput("Phone number	: ", &contact.phoneNumber);
			catchInput("Darkest secret	: ", &contact.darkestSecret);
			std::cout << std::endl;
			phonebook.addContact(contact);


		} else if (usrInput == "SEARCH" || usrInput == "search") {
			if (phonebook.showAll()) {
				std::string str_index;
				while (!isdigit(str_index[0]))
					catchInput("Select a contact : ", &str_index);
				phonebook.showContact(str_index);
			}

		} else if (usrInput == "EXIT" || usrInput == "exit") {
			std::cout << "Exit Phonebook\n";
			exit(1);
		} else {
			std::cout << "Command not found\n";
		}
	}
	std::cout << "Exit Phone Book\n";	
	return (0);
}