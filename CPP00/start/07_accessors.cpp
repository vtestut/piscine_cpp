#include "07_accessors.hpp"

MyClass::MyClass(int v) {
	v = v + 1;
	std::cout << "Constructor called" << std::endl;
	std::cout << "_foo = " << this->_foo << std::endl;
	return;
}

MyClass::~MyClass(void) {
	std::cout << "Destructor called" << std::endl;
	return;
}

int		MyClass::getFoo(void) const {
	return this->_foo;
}

void	MyClass::setFoo(int n) {
	if(n >= 0)
		this->_foo = n;
	return;
}

int MyClass::compareFoo(MyClass *other) const {
	if (this->_foo < other->_foo)
		return -1;
	else if (this->_foo > other->_foo)
		return 1;
	else if (this->_foo == other->_foo)
		return 2;
	else
		return 0;
}

int main(void) {

	MyClass instance1(111);
	MyClass instance2(666);

	instance1.setFoo(42);
	instance2.setFoo(42);
	std::cout << "instance.getFoo() = " << instance1.getFoo() << std::endl;
	instance1.setFoo(-42);
	std::cout << "instance.getFoo() = " << instance1.getFoo() << std::endl;
	
	std::cout << "\n*************************************************\n\n";
	std::cout << "instance2.compareFoo(instance1) = " << instance2.compareFoo(&instance1) << std::endl;
	
	std::cout << "\n*************************************************\n\n";
	return 0;
}