#include "03_attributs.hpp"

/*  -	CONTRUCTEUR
    *	Le constructeur etant appele des la declaration de la class,
    *	il peut etre utile pour initialiser les attributs */
MyClass::MyClass( void ) {
	std::cout << "Constructeur	'MyClass' a ete appele" << std::endl;
	this->foo = 42;
	std::cout << "\nInitialisation de 'foo' DANS le constructeur\nfoo = " << this->foo << "\n";
	std::cout << "\nappel de la fonction membre 'func()' DANS le constructeur:\n";
	this->func();
	return;
}

MyClass::~MyClass( void ) {
	std::cout << "Destructeur	'~MyClass' a ete appele\n\n";
	return;
}

void	MyClass::func( void ) {
	std::cout << "func() says : COUCOU !\n\n";
}


/**********************************************************************************************************************/

int main(void)
{
	MyClass myVar;

	myVar.foo = 666;
	std::cout << myVar.foo << "\n";
	return (0);
}