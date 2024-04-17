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
		std::cout << RED "MateriaSource error !" RESET << std::endl;
		return;
	}
	for (int i = 0; i < this->_maxRecipes; i++) {
		if (this->_recipes[i] == NULL) {
			this->_recipes[i] = materia;
			std::cout << GREEN "MateriaSource learned : " << materia->getType() << RESET << std::endl;
			return;
		}
	}
	std::cout << RED "MateriaSource can't learn more materia." RESET << std::endl;
	delete materia;
}

AMateria * MateriaSource::createMateria(const std::string & type) {
	for (int i = 0; i < this->_maxRecipes; i++) {
		if (this->_recipes[i]
			&& this->_recipes[i]->getType() == type) {
			std::cout << GREEN "MateriaSource created : " << type << RESET << std::endl;
			return (this->_recipes[i]->clone());
		}
	}
	std::cout << RED "MateriaSource doesn't know the type \"" << type << "\"." RESET << std::endl;
	return (NULL);
}

const std::string MateriaSource::toDisplay() const {
	std::string s = "MateriaSource(";
	for (int i = 0; i < MateriaSource::_maxRecipes; ++i) {
		if (i != 0)
			s += ", ";
		s += this->_recipes[i] ? this->_recipes[i]->getType() : "empty";
	}
	s += ")";
	return s;
}

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

MateriaSource::MateriaSource() {
	this->_initializeEmptyRecipes();
}

MateriaSource::MateriaSource(const MateriaSource & obj) {
	this->_initializeEmptyRecipes();
	*this = obj;
}

MateriaSource::~MateriaSource() {
	this->_deleteRecipes();
}

/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/

MateriaSource &	MateriaSource::operator=(const MateriaSource & obj) {
	this->_deleteRecipes();
	for (int i = 0; i < this->_maxRecipes; i++) {
		if (obj._recipes[i] != NULL)
			this->_recipes[i] = obj._recipes[i]->clone();
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& os, MateriaSource const& materiaSource) {
	return os << materiaSource.toDisplay() << std::endl;
}