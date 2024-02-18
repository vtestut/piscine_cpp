#include "09_pointers_to_members.hpp"

MyClass::MyClass(void) : foo(666) {
	std::cout << "Constructor called\n";
	return;
}

MyClass::~MyClass(void) {
	std::cout << "Destructor called\n";
	return;
}

void	MyClass::bar(void) const {
	std::cout << "Member function 'bar' called\n";
	return;
}

int main(void)
{
	MyClass		mon_instance;
	MyClass		*ptr_sur_instance = &mon_instance; // pointeur classique, vaut l'adresse de 'mon_instance'
	
	int			MyClass::*ptr_sur_attribut = NULL; // Permet de recup l'adresse d'un attribut membre d'une classe

	ptr_sur_attribut = &MyClass::foo; // prend l'adresse de l'int foo de la classe MyClass
	std::cout << "Value of member foo : " << mon_instance.foo << std::endl;
	
	mon_instance.*ptr_sur_attribut = 21; // l'operateur .* permet d'acceder et modifier l'attribut membre foo de l'instance precisee
	std::cout << "Value of member foo : " <<mon_instance.foo << std::endl;
	
	ptr_sur_instance->*ptr_sur_attribut = 42; // l'operateur ->* permet d'acceder et modifier l'attribut d'un pointeur sur instance
	std::cout << "Value of member foo : " <<mon_instance.foo << std::endl;
	
	
	void		(MyClass::*f)(void) const; // pointeur sur fonction membre d'une classe

	f = &MyClass::bar;

	(mon_instance.*f)();
	(ptr_sur_instance->*f)();

	return 0;
}