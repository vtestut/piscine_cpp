#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <ios>
# include <sstream>

# include "Contact.hpp"

class PhoneBook {

public :

	void addContact(Contact current_contact);
	void showContact(std::string str_index) const;
	bool showAll() const;

private :

	static const int	_max_usr = 8;
	static const int	_width = 10;
	static int			_index;
	static int			_n;
	Contact 			contacts[_max_usr];

	bool is_valid_index(std::string str_index, int* num_index) const;
	void printColumn(std::string str) const;
};

#endif