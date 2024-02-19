#include "08_non_membre.hpp"

MyClass::MyClass() {
	std::cout << "Constructor called" << std::endl;
	MyClass::_nbInstances += 1;
	return;
}

MyClass::~MyClass() {
	std::cout << "Destructor called" << std::endl;
	MyClass::_nbInstances -= 1;
	return;
}

int MyClass::getNbInstances(void) {
	return MyClass::_nbInstances;
}

// The static member is defined outside the class to avoid 
// undefined value before creating an instance of the class
int MyClass::_nbInstances = 0;

void f0(void) {
	MyClass a;
	std::cout << "Nb instances: " << MyClass::getNbInstances() << std::endl;
	return;
}

void f1(void) {
	MyClass a;
	std::cout << "Nb instances: " << MyClass::getNbInstances() << std::endl;
	f0();
	return;
}

int main(void) {

	std::cout << "Nb instances: " << MyClass::getNbInstances() << std::endl;
	f1();
	std::cout << "Nb instances: " << MyClass::getNbInstances() << std::endl;
	// MyClass a;
	// std::cout << "Nb instances: " << MyClass::getNbInstances() << std::endl;
	return 0;
}