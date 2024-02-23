#include "PhoneBook.hpp"

int PhoneBook::_index = -1;
int PhoneBook::_n=0;

/*	Pour definir une fonction memebre en C++ il faut 
	commencer par preciser le type de retour comme en C
	puis preciser le nom de classe ou il y a la fonction
	puis ajouter l'operateur de resolution de portee ' :: ' suivi de la fonction
	ajouter 'const' apres les parametres si la fonction ne modifiera jamais l'instance/l'objet */
void PhoneBook::addContact(Contact current_contact) {
	if (this->_index == -1 || this-> _index == this->_maxUsr)
		this->_index = 0;
	this->contacts[_index] = current_contact;
	this->_index++;
	if (this->_n < this->_maxUsr)
		this->_n++;
}

void PhoneBook::printColumn(std::string str) const {
	if (str.size() > this->_width)
		str = str.substr(0, this->_width - 1) + '.';
	std::cout << RESET << "|";
	std::cout << CYAN << std::right << std::setw(this->_width) << str;
}

bool PhoneBook::is_valid_index(std::string str_index, int* num_index) const {
	*num_index = 0;
	for (size_t i = 0; i < str_index.size(); ++i) {
		if (str_index == "" || str_index.size() > 1 || !isdigit(str_index[0])) {
			std::cout << RED << "\ninvalid index\n";
			return false;
		}
		*num_index = (10 * *num_index + str_index[i] - '0') -1;
		if (*num_index >= this->_n) {
			std::cout << RED << "\ninvalid index\n";
			return false;
		}
	}
	return true;
}

void PhoneBook::showContact(std::string str_index) const {
	int num_index;
	if (is_valid_index(str_index, &num_index)) {
		std::cout << CYAN << std::endl << "First name\t: " << RESET;
		std::cout << this->contacts[num_index].firstName << std::endl;
		std::cout << CYAN << "Last name\t: " << RESET;
		std::cout << this->contacts[num_index].lastName << std::endl;
		std::cout << CYAN << "Nickname\t: " << RESET;
		std::cout << this->contacts[num_index].nickName << std::endl;
		std::cout << CYAN << "Phone number\t: " << RESET;
		std::cout << this->contacts[num_index].phoneNumber << std::endl;
		std::cout << CYAN << "Darkest secret\t: " << RESET;
		std::cout << this->contacts[num_index].darkestSecret << std::endl;
		std::cout << CYAN << "\nSelect enter to return. ";
		char key;
		while (std::cin.get(key)) {
			if (key == '\n') {
				std::cout << CLEAR;
				break;
			}
		}
	}
}

bool PhoneBook::showAll() const {
	if (_index == -1) {
		std::cout << RED << CLEAR << "\nNo contact yet.\n";
		return false;
	}
	std::cout << CYAN << std::endl;
	std::cout << CYAN << std::right << std::setw(this->_width) << "Index";
	printColumn("firstname");
	printColumn("lastname");
	printColumn("nickname");
	std::cout << std::endl << std::right << std::setw(this->_width) << "";
	printColumn("");
	printColumn("");
	printColumn("");
	std::cout << CYAN << std::endl;
	for (int i = 0; i < _n ; ++i) {
		Contact contact_tmp = this->contacts[i];
		std::cout << GREEN << std::right << std::setw(this->_width) << i+1 << RESET;
		printColumn(contact_tmp.firstName);
		printColumn(contact_tmp.lastName);
		printColumn(contact_tmp.nickName);
		std::cout << CYAN << std::endl;
	};
	std::cout << CYAN << std::endl;
	return true;
}



