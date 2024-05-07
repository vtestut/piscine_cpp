#include "Base.hpp"

Base *generate(void);
void identify(Base* p);
void identify(Base& p);

int main() {
	A a;
	B b;
	C c;

	std::srand(std::time(NULL));
	Base* r1 = generate();
	Base* r2 = generate();
	Base* r3 = generate();

	identify(&a);
	identify(&b);
	identify(&c);
	identify(r1);
	identify(r2);
	identify(r3);

	std::cout << std::endl;

	identify(a);
	identify(b);
	identify(c);
	identify(*r1);
	identify(*r2);
	identify(*r3);

	delete r1;
	delete r2;
	delete r3;
}
