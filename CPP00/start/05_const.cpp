#include "05_const.hpp"

/*	
*	Je peux initialiser une variable const via le constructeur */
Sample::Sample(float const f) : pi(f), qd(42) {
	std::cout << "Constructor called" << std::endl;
	return;
}

Sample::~Sample(void) {
	std::cout << "Destructor called" << std::endl;
	return;
}

/*
*	Quand une fonction membre est déclarée const, 
*	elle ne peut pas modifier les attributs de l'objet. */
void	Sample::bar(void) const {
	std::cout << "Member function bar called" << std::endl;
	std::cout << "pi = " << this->pi << std::endl;
	std::cout << "qd = " << this->qd << std::endl;
	return;
}

int main(void) {
	Sample instance(3.14f);

	instance.bar();
	return 0;
}