#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <ios>
# include <string>
# include <sstream>
// # include <unistd.h>

# include "Contact.hpp"

# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define CYAN	"\033[36m"
# define CLEAR	"\033[2J\033[1;1H"
# define RESET	"\033[0m"

class PhoneBook {

public :

	void addContact(Contact current_contact);
	void showContact(std::string str_index) const;
	bool showAll() const;

private :

	static const int	_maxUsr = 8;
	static const int	_width = 10;
	static int			_index;
	static int			_n;
	Contact 			contacts[_maxUsr];

	bool is_valid_index(std::string str_index, int* num_index) const;
	void printColumn(std::string str) const;
};

#endif