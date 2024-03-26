#include "Brain.hpp"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

Brain::Brain() {
	for (int i = 0; i < NUM_IDEAS; i++)
		this->ideas[i] = "Pierre qui roule n'amasse pas mousse.";
	std::cout << "Brain constructed.\n";
}

Brain::Brain(const Brain & brain) {
	for (int i = 0; i < NUM_IDEAS; i++)
		this->ideas[i] = brain.ideas[i];
	std::cout << "Brain copied.\n";
}

Brain::~Brain() {
	std::cout << "Brain destructed.\n";
}

/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/

Brain& Brain::operator=(const Brain & brain) {
	if (this != &brain)
		for (int i = 0; i < NUM_IDEAS; i++)
			this->ideas[i] = brain.ideas[i];
	std::cout << "Brain assigned.\n";
	return (*this);
}
