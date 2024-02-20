#include "phonebook.hpp"

void PhoneBook::addContact(Contact current_contact) {
	if (this->contacts_deque.size() > this->max_usr)
		this->contacts_deque.pop_front();
	this->contacts_deque.push_back(current_contact);
}

void PhoneBook::displayColumn(std::string str) {
	if (str.size() > this->width)
		str = str.substr(0, this->width - 1) + '.';
	std::cout << "|";
	std::cout << std::right << std::setw(this->width) << str;
}

void PhoneBook::clearContactsDeque() {
	this->contacts_deque.clear();
}

bool PhoneBook::showAll() {
	if (this->contacts_deque.size() == 0) {
		std::cout << "No contacts have been created yet." << std::endl;
		return false;
	}
	std::cout << std::endl;
	std::cout << std::right << std::setw(this->width) << "Index";
	displayColumn("firstname");
	displayColumn("lastname");
	displayColumn("nickname");
	std::cout << std::endl;
	std::cout << std::right << std::setw(this->width) << "";
	displayColumn("");
	displayColumn("");
	displayColumn("");
	std::cout << std::endl;
	for (size_t i = 0; i < this->contacts_deque.size(); ++i) {
		Contact contact_tmp = this->contacts_deque[i];
		std::cout << std::right << std::setw(this->width) << i;
		displayColumn(contact_tmp.firstName);
		displayColumn(contact_tmp.lastName);
		displayColumn(contact_tmp.nickName);
		std::cout << std::endl;
	};
	std::cout << std::endl;
	return true;
}

bool PhoneBook::is_valid_index(std::string str_index, int* num_index) {
	*num_index = 0;
	for (size_t i = 0; i < str_index.size(); ++i) {
		if (str_index == "" || str_index.size() > 1 || !isdigit(str_index[0])) {
			std::cout << "0 < n < 9\n";
			return false;
		}
		*num_index = 10 * *num_index + str_index[i] - '0';
		if ((size_t)*num_index >= this->contacts_deque.size())
			return false;
	}
	return true;
}

void PhoneBook::showContact(std::string str_index) {
	int num_index;
	if (is_valid_index(str_index, &num_index)) {
		std::cout << std::endl << "First name	: ";
		std::cout << this->contacts_deque[num_index].firstName << std::endl;
		std::cout << "Last name	: ";
		std::cout << this->contacts_deque[num_index].lastName << std::endl;
		std::cout << "Nickname	: ";
		std::cout << this->contacts_deque[num_index].nickName << std::endl;
		std::cout << "Phone number	: ";
		std::cout << this->contacts_deque[num_index].phoneNumber << std::endl;
		std::cout << "Darkest secret	: ";
		std::cout << this->contacts_deque[num_index].darkestSecret << std::endl;
		std::cout << std::endl;
	} else if (is_valid_index(str_index, &num_index)) {
		std::cout << "index is not valid" << std::endl;
	}
}