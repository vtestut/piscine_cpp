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

	static const int _maxUsr = 8;
	static const int _width = 10;
	
	std::deque <Contact> contacts;

	bool is_valid_index(std::string str_index, int* num_index);
	void printColumn(std::string str);
};

#endif