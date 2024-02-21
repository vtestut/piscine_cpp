#include "PhoneBook.hpp"

int PhoneBook::_index = -1;
int PhoneBook::_n=0;

void PhoneBook::addContact(Contact current_contact) {
	if (this->_index == -1 || this-> _index == this->_max_usr)
		this->_index = 0;
	this->contacts[_index] = current_contact;
	this->_index++;
	if (this->_n < this->_max_usr)
		this->_n++;
}

void PhoneBook::printColumn(std::string str) const {
	if (str.size() > this->_width)
		str = str.substr(0, this->_width - 1) + '.';
	std::cout << "|";
	std::cout << std::right << std::setw(this->_width) << str;
}

bool PhoneBook::showAll() const {
	if (_index == -1) {
		std::cout << "\nNo contact yet." << std::endl;
		return false;
	}
	std::cout << std::endl;
	std::cout << std::right << std::setw(this->_width) << "Index";
	printColumn("firstname");
	printColumn("lastname");
	printColumn("nickname");
	std::cout  << std::endl << std::right << std::setw(this->_width) << "";
	printColumn("");
	printColumn("");
	printColumn("");
	std::cout << std::endl;
	for (int i = 0; i < _n ; ++i) {
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

bool PhoneBook::is_valid_index(std::string str_index, int* num_index) const {
	*num_index = 0;
	for (size_t i = 0; i < str_index.size(); ++i) {
		if (str_index == "" || str_index.size() > 1 || !isdigit(str_index[0])) {
			std::cout << "\ninvalid index\n";
			return false;
		}
		*num_index = 10 * *num_index + str_index[i] - '0';
		if (*num_index >= this->_index) {
			std::cout << "\ninvalid index\n";
			return false;
		}
	}
	return true;
}

void PhoneBook::showContact(std::string str_index) const {
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
		// std::cout << std::endl;
	}
}