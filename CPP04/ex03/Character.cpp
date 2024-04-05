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
		std::cout << RED << this->_name
			<< ": Can't equip something that doesn't exist!" RESET << std::endl;
		return;
	}
	for (int i = 0; i < this->_inventorySize; i++) {
		if (this->_inventory[i] == NULL) {
			this->_inventory[i] = materia;
			std::cout << GREEN << this->_name << " equipped " << materia->getType() << " materia to inventory index " << i << "." RESET << std::endl;
			return;
		}
	}
	std::cout << RED << this->_name << ": I can't carry any more materia!" RESET << std::endl;
}

void Character::unequip(int index) {
	if (index < 0 || index >= this->_inventorySize) {
		std::cout << RED << this->_name << ": I can't unequip anything from inventory index " << index << ". It's not a valid index!" RESET << std::endl;
		return;
	} 
	if (this->_inventory[index] == NULL) {
		std::cout << RED << this->_name << ": I don't have anything at index " << index << " to unequip!" RESET << std::endl;
		return;
	}
	std::cout << GREEN << this->_name << " unequipped " << this->_inventory[index]->getType() << " materia from inventory index " << index << "." RESET << std::endl;
	this->_inventory[index] = NULL;	
}

void Character::use(int index, ICharacter & target) {
	if (index < 0 || index >= this->_inventorySize) {
		std::cout << this->_name << ": " RED "Can't use item at inventory index " << index << ". It's not a valid index!" RESET << std::endl; 
		return;
	} 
	if (this->_inventory[index] != NULL) {
		std::cout << this->_name << ": ";
		this->_inventory[index]->use(target);
	} 
	else
		std::cout << this->_name << ": "  RED "Oops, I don't have an item in my inventory at index " << index << "!" RESET << std::endl;
	return ;
}

void Character::displayInventory() const {
	std::cout << this->_name << "'s inventory contains:" << std::endl;
	for (int i = 0; i < this->_inventorySize; i++) {
		std::cout << "\t[" << i << "] ";
		if (this->_inventory[i] == NULL)
			std::cout << "Empty slot.";
		else
			std::cout << this->_inventory[i]->getType() << " materia.";
		std::cout << std::endl; }
	return ;
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
	std::cout << CYAN "Character default constructor called." RESET << std::endl;
	this->_initializeEmptyInventory();
}

// a deep copy
// the Materias of a Character must be deleted before the new ones are added to their inventory
/*Character::Character(Character const & src) {
  *this = src;
  std::cout << "Character   " << this->_name << " copy     constructor" << std::endl; }*/ 
Character::Character(const Character & obj) {
	std::cout << CYAN "Character copy constructor called." RESET << std::endl;
	this->_initializeEmptyInventory();
	*this = obj;
}

Character::Character(const std::string & name) : _name(name) {
	std::cout << CYAN "Character name constructor called with name \"" << this->_name << "\"." RESET << std::endl;
	this->_initializeEmptyInventory();
}

Character::~Character() {
	std::cout << CYAN "Character destructor called for \"" << this->_name << "\"." RESET << std::endl;
	this->_deleteInventory();
}

/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/

// a deep copy
Character &	Character::operator=(const Character & obj) {
	std::cout << CYAN "Character assignment operator overload called." RESET << std::endl;
	this->_name = obj._name;
	this->_deleteInventory();
	for (int i = 0; i < this->_inventorySize; i++) {
		if (obj._inventory[i] != NULL)
			this->_inventory[i] = obj._inventory[i]->clone();
	}
	return (*this);
}