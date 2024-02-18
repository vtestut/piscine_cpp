#include "04_initialization_list.hpp"

MyClass::MyClass(char p1, int p2, float p3) : c1(p1), c2(p2), c3(p3) {

	std::cout << "Constructor called\n";
	std::cout << "this->c1 = " << this->c1;
	std::cout << "\nthis->c2 = " << this->c2;
	std::cout << "\nthis->c3 = " << this->c3;
}

MyClass::~MyClass(){
	std::cout << "Destuctor called\n";
}

int main(void)
{
	MyClass MyVar('A', 1, 2.5);
	return 0;
}