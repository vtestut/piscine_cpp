#ifndef POINTERS_TO_MEMBERS_HPP
#	define POINTERS_TO_MEMBERS_HPP

#include <iostream>

class MyClass {

public:

	int foo;
	MyClass();
	~MyClass();

	void bar(void) const;
};

#endif