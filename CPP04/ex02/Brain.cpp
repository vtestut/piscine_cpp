#include "Brain.hpp"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

Brain::Brain() {
	for (int i = 0; i < NUM_IDEAS; i++)
		this->ideas[i] = "Mens sana in corpore sano";
	std::cout << GREEN "Brain constructed" RESET << std::endl;
}

Brain::Brain(const Brain & obj) {
	for (int i = 0; i < NUM_IDEAS; i++)
		this->ideas[i] = obj.ideas[i];
	std::cout << GREEN "Brain copied" RESET << std::endl;
}

Brain::~Brain() {
	std::cout << RED "Brain destructed" RESET << std::endl;
}

/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/

Brain& Brain::operator=(const Brain & obj) {
	if (this != &obj)
		for (int i = 0; i < NUM_IDEAS; i++)
			this->ideas[i] = obj.ideas[i];
	std::cout << GREEN "Brain assigned" RESET << std::endl;
	return (*this);
}
