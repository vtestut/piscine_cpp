#include "MateriaSource.hpp"
#include <iostream>

/******************************************************************************/
/*								PRIVATE										  */
/******************************************************************************/

void MateriaSource::_initializeEmptyRecipes() {
	for (int i = 0; i < this->_maxRecipes; i++)
		this->_recipes[i] = NULL;
	return ;
}

void MateriaSource::_deleteRecipes() {
	for (int i = 0; i < this->_maxRecipes; i++) {
		if (this->_recipes[i] != NULL) {
			delete this->_recipes[i];
			this->_recipes[i] = NULL;
		}
	}
}

/******************************************************************************/
/*								PUBLIC										  */
/******************************************************************************/

void MateriaSource::learnMateria(AMateria * materia) {
	if (!materia) {
		std::cout << RED "MateriaSource was not provided with a materia to learn." RESET << std::endl;
	}
	for (int i = 0; i < this->_maxRecipes; i++) {
		if (this->_recipes[i] == NULL) {
			this->_recipes[i] = materia;
			std::cout << GREEN "MateriaSource learned the " << materia->getType() << " materia recipe." RESET << std::endl;
			return;
		}
	}
	std::cout << RED "MateriaSource can't learn any more materia." RESET << std::endl;
	delete materia;
}

AMateria * MateriaSource::createMateria(const std::string & type) {
	for (int i = 0; i < this->_maxRecipes; i++) {
		if (this->_recipes[i]
			&& this->_recipes[i]->getType() == type) {
			std::cout << GREEN "MateriaSource creating " << type << " materia." RESET << std::endl;
			return (this->_recipes[i]->clone());
		}
	}
	std::cout << RED "MateriaSource does not know the type \"" << type << "\"." RESET << std::endl;
	return (NULL);
}

void MateriaSource::displayKnownRecipes() {
	std::cout << "MateriaSource knows the following recipes:" << std::endl;
	for (int i = 0; i < this->_maxRecipes; i++)
	{
		std::cout << "\t[" << i << "] ";
		if (this->_recipes[i] == NULL)
			std::cout << "Empty slot.";
		else
			std::cout << this->_recipes[i]->getType() << " materia.";
		std::cout << std::endl;
	}
	return ;
}

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

MateriaSource::MateriaSource() {
	std::cout << CYAN "MateriaSource default constructor called." RESET << std::endl;
	this->_initializeEmptyRecipes();
}

MateriaSource::MateriaSource(const MateriaSource & obj) {
	std::cout << CYAN "MateriaSource copy constructor called." RESET << std::endl;
	this->_initializeEmptyRecipes();
	*this = obj;
}

MateriaSource::~MateriaSource() {
	std::cout << CYAN "MateriaSource destructor called." RESET << std::endl;
	this->_deleteRecipes();
}

/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/

MateriaSource &	MateriaSource::operator=(const MateriaSource & obj) {
	std::cout << CYAN "MateriaSource assignment operator overload called." RESET << std::endl;
	this->_deleteRecipes();
	for (int i = 0; i < this->_maxRecipes; i++) {
		if (obj._recipes[i] != NULL)
			this->_recipes[i] = obj._recipes[i]->clone();
	}
	return (*this);
}