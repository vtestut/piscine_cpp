#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream> // cout cin
# include <string>
# include <iomanip> //setw
# include <ios> // right
# include <deque> // push pop
# include <sstream> // flush

# include "contact.hpp"

class PhoneBook {

public :

	void addContact(Contact current_contact);
	void showContact(std::string str_index);
	bool showAll();
	void clearContactsDeque();

private :

	static const int max_usr = 8;
	static const int width = 10;
	
	std::deque <Contact> contacts_deque;

	bool is_valid_index(std::string str_index, int* num_index);
	void displayColumn(std::string str);
};

#endif