#include "Character.hpp"
#include <iostream>
#include <string>

/******************************************************************************/
/*								PRIVATE										  */
/******************************************************************************/

void Character::_initializeEmptyInventory() {
	for (int i = 0; i < this->_inventorySize; i++)
		this->_inventory[i] = NULL;
}

void Character::_deleteInventory() {
	for (int i = 0; i < this->_inventorySize; i++) {
		if (this->_inventory[i] != NULL) {
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
	}
}

/******************************************************************************/
/*								PUBLIC										  */
/******************************************************************************/

void Character::equip(AMateria * materia) {
	if (!materia) {
		std::cout << this->_name << ":" RED " Can't equip a non existent materia" RESET << std::endl;
		return;
	}
	for (int i = 0; i < this->_inventorySize; i++) {
		if (this->_inventory[i] == NULL) {
			this->_inventory[i] = materia;
			std::cout << GREEN << this->_name << " equipped " << materia->getType() << " materia to slot " << i << "." RESET << std::endl;
			return;
		}
	}
	std::cout << this->_name << ":" RED " inventory is full" RESET << std::endl;
	delete materia;
}

void Character::unequip(int index) {
	if (index < 0 || index >= this->_inventorySize) {
		std::cout << this->_name << ":" RED " can't unequip slot " << index << " is invalid !" RESET << std::endl;
		return;
	} 
	if (this->_inventory[index] == NULL) {
		std::cout << this->_name << ":" RED " Can't unequip slot " << index << " is empty !" RESET << std::endl;
		return;
	}
	std::cout << GREEN << this->_name << " unequipped " << this->_inventory[index]->getType() << " materia from slot " << index << "." RESET << std::endl;
	this->_inventory[index] = NULL;	
}

void Character::use(int index, ICharacter & target) {
	if (index < 0 || index >= this->_inventorySize) {
		std::cout << this->_name << ": " RED "Slot " << index << " is invalid !" RESET << std::endl; 
		return;
	} 
	if (this->_inventory[index] != NULL) {
		std::cout << this->_name << ": ";
		this->_inventory[index]->use(target);
	} 
	else
		std::cout << this->_name << ": "  RED "Slot " << index << " is empty !" RESET << std::endl;
	return ;
}

const std::string Character::toDisplay() const {
	std::string s = "Character = " + this->_name + " (";
	for (int i = 0; i < Character::_inventorySize; ++i) {
		if (i != 0)
			s += ", ";
		s += this->_inventory[i] ? this->_inventory[i]->getType() : "empty";
	}
	s += ")";
	return s;
}

/******************************************************************************/
/*							ACCESSORS										  */
/******************************************************************************/

std::string const &	Character::getName() const {
	return (this->_name);
}

void Character::setName(const std::string & newName) {
	this->_name = newName;
}

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

Character::Character() : _name("Unnamed") {
	this->_initializeEmptyInventory();
}

Character::Character(const Character & obj) {
	this->_initializeEmptyInventory();
	*this = obj;
}

Character::Character(const std::string & name) : _name(name) {
	this->_initializeEmptyInventory();
}

Character::~Character() {
	this->_deleteInventory();
}

/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/

Character &	Character::operator=(const Character & obj) {
	this->_name = obj._name;
	this->_deleteInventory();
	for (int i = 0; i < this->_inventorySize; i++) {
		if (obj._inventory[i] != NULL)
			this->_inventory[i] = obj._inventory[i]->clone();
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& os, Character const& character) {
	return os << character.toDisplay() << std::endl;
}