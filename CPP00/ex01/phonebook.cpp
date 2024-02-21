#include "PhoneBook.hpp"

int PhoneBook::_index = -1;
// int PhoneBook::_PET = 0;

void PhoneBook::addContact(Contact current_contact) {
	if (_index == -1 || _index == _max_usr)
		_index = 0;
	std::cout << "avant creation _index = " << _index << std::endl; 
	this->contacts[_index] = current_contact;
	_index++;
	std::cout << "après creation _index = " << _index << std::endl; 
}

void PhoneBook::printColumn(std::string str) {
	if (str.size() > this->_width)
		str = str.substr(0, this->_width - 1) + '.';
	std::cout << "|";
	std::cout << std::right << std::setw(this->_width) << str;
}

bool PhoneBook::showAll() {
	if (_index == -1) {
		std::cout << "No contact yet." << std::endl;
		return false;
	}
	std::cout << std::endl;
	std::cout << std::right << std::setw(this->_width) << "Index";
	printColumn("firstname");
	printColumn("lastname");
	printColumn("nickname");
	std::cout << std::endl;
	std::cout << std::right << std::setw(this->_width) << "";
	printColumn("");
	printColumn("");
	printColumn("");
	std::cout << std::endl;
	for (int i = 0; i < _max_usr ; ++i) {
		Contact contact_tmp = this->contacts[i];
		std::cout << std::right << std::setw(this->_width) << i;
		printColumn(contact_tmp.firstName);
		printColumn(contact_tmp.lastName);
		printColumn(contact_tmp.nickName);
		std::cout << std::endl;
	};
	std::cout << std::endl;
	return true;
}

bool PhoneBook::is_valid_index(std::string str_index, int* num_index) {
	*num_index = 0;
	for (size_t i = 0; i < str_index.size(); ++i) {
		// if (str_index == "" || str_index.size() > 1 || !isdigit(str_index[0])) {
		// 	std::cout << "0 < n < 9\n";
		// 	return false;
		// }
		*num_index = 10 * *num_index + str_index[i] - '0';
		if (*num_index >= this->_index)
			return false;
	}
	return true;
}

void PhoneBook::showContact(std::string str_index) {
	int num_index;
	if (is_valid_index(str_index, &num_index)) {
		std::cout << std::endl << "First name	: ";
		std::cout << this->contacts[num_index].firstName << std::endl;
		std::cout << "Last name	: ";
		std::cout << this->contacts[num_index].lastName << std::endl;
		std::cout << "Nickname	: ";
		std::cout << this->contacts[num_index].nickName << std::endl;
		std::cout << "Phone number	: ";
		std::cout << this->contacts[num_index].phoneNumber << std::endl;
		std::cout << "Darkest secret	: ";
		std::cout << this->contacts[num_index].darkestSecret << std::endl;
		std::cout << std::endl;
	} else if (is_valid_index(str_index, &num_index)) {
		std::cout << "index is not valid" << std::endl;
	}
}