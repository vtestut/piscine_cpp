#include "Brain.hpp"

/******************************************************************************/
/*								ACCESSORS									  */
/******************************************************************************/

std::string * Brain::getIdeas() {
  return (this->ideas);
}

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

Brain::Brain() {
	this->ideas = new std::string[NB_IDEAS];
	for (int i = 0; i < NB_IDEAS; i++) 
		this->ideas[i] = "Cogito, Ergo Sum.";
	std::cout << GREEN "Brain constructed" RESET << std::endl;
}

Brain::Brain(const Brain & obj) {
	*this = obj;
	std::cout << GREEN "Brain copied" RESET << std::endl;
}

Brain::~Brain() {
	std::cout << RED "Brain destructed" RESET << std::endl;
  delete [] this->ideas;
}

/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/

Brain & Brain::operator = (const Brain & obj) {
	this->ideas = new std::string[NB_IDEAS];
	for (int i = 0; i < NB_IDEAS; i++)
		this->ideas[i] = obj.ideas[i];
	std::cout << GREEN "Brain assigned" RESET << std::endl;
	return (*this);
}