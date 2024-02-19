#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

enum e_type {
	_NULL	= 0,
	TEXT	= 1,
	NUM		= 2,
	SECRET	= 3,
};

class Contact {

public:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;
	Contact(){};
};

#endif