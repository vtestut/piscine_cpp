#include "06_public_private.hpp"

/*
*	Le constructeur est un membre public de la classe.
*	Il peut donc être appelé depuis l'extérieur de la classe. 
*	Le constructeur initialise les attributs de l'objet. 
*	Il est appelé automatiquement lors de la création de l'objet. 
*	Il n'a pas de type de retour. 
*	Il peut acceder au attributs privés de la classe.
*/
Sample::Sample(void) {
	std::cout << "Constructor called" << std::endl;
	this->publicFoo = 0;
	std::cout << "publicFoo = " << this->publicFoo << std::endl;
	this->_privateFoo = 0;
	std::cout << "_privateFoo = " << this->_privateFoo << std::endl;

	this->publicBar();
	this->_privateBar();

	return;
}

Sample::~Sample(void) {
	std::cout << "Destructor called" << std::endl;
	return;
}

void	Sample::publicBar(void) const {
	std::cout << "Member function publicBar called" << std::endl;
	return;
}

void	Sample::_privateBar(void) const {
	std::cout << "Member function _privateBar called" << std::endl;
	return;
}

int main(void) {
	Sample instance;

	instance.publicBar();
	// error: ‘void Sample::_privateBar() const’ is private within this context
	// instance._privateBar(); 
	return 0;
}