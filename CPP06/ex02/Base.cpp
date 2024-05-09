#include "Base.hpp"

Base* generate() {
    // srand(time(NULL));
	int n = rand() % 3;
	if (n == 0)
		return std::cout<<"generated A\n", new A;
	else if (n == 1)
		return std::cout<<"generated B\n", new B;
	else
		return std::cout<<"generated C\n", new C;
}

void identify(Base* p) {
	std::cout << CYAN "with ptr -> ";
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A" RESET << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B" RESET << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C" RESET << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void identify(Base& p) {
	std::cout << YELLOW "with ref -> ";
	try {
		A& ref = dynamic_cast<A&>(p);
		(void)ref;
		std::cout << "A" RESET << std::endl;
		return;
	} catch (...) {}
	try {
		B& ref = dynamic_cast<B&>(p);
		(void)ref;
		std::cout << "B" RESET << std::endl;
		return;
	} catch (...) {}
	try {
		C& ref = dynamic_cast<C&>(p);
		(void)ref;
		std::cout << "C" RESET << std::endl;
	return;
	} catch (...) {}

	std::cout << "Unknown" << std::endl;
}
