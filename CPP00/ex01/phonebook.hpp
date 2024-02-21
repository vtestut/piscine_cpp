#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream> // cout cin
# include <string>
# include <iomanip> //setw
# include <ios> // right
# include <deque> // push pop
# include <sstream> // flush

# include "Contact.hpp"

class PhoneBook {

public :

	void addContact(Contact current_contact);
	void showContact(std::string str_index);
	bool showAll();

private :

	// static int			_PET;
	static int			_index;
	static const int	_max_usr = 8;
	static const int	_width = 10;
	Contact 			contacts[_max_usr];

	bool is_valid_index(std::string str_index, int* num_index);
	void printColumn(std::string str);
};

#endif