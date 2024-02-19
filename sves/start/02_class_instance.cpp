#include <iostream>
#include "02_class_instance.hpp"

MyClass::MyClass( void ) {

	std::cout << "Constructeur	'MyClass'	a ete appele" << std::endl;
	return;
}

MyClass::~MyClass( void ) {
	std::cout << "Destructeur	'~MyClass'	a ete appele\n\n";
	return;
}

void	MyClass::func( void ) {
	std::cout << "\nFonction membre 'func()'	a ete appele	COUCOU !\n";
}

int main(void)
{
	std::cout << "Declaration de la variable 'Ma_Var_Class' de type 'MyClass' (= class) :\n\n";

	MyClass Ma_Var_Class;

	Ma_Var_Class.foo = 42;
	Ma_Var_Class.bar = new int;
	*(Ma_Var_Class.bar) = 66;

	std::cout << "\nfoo	=	" << Ma_Var_Class.foo << "\n";
	std::cout << "bar	=	" << *(Ma_Var_Class.bar) << "\n";

	Ma_Var_Class.func();

	delete Ma_Var_Class.bar;

	std::cout << "\n\n.\n..\n... Fin du program\n\n\n";
	return (0);
}