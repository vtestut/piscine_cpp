#include "Base.hpp"

Base *generate(void);
void identify(Base* p);
void identify(Base& p);

// Function to generate a random instance of A, B, or C
Base *generate(void) {
    // srand(time(NULL));
    switch (rand() % 3) {
    case 0:
        return new A;
    case 1:
        return new B;
    case 2:
        return new C;
    default:
        return NULL; // Just in case
    }
}

// Function to identify from Base pointer
void identify(Base* p) {
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "A\n";
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "B\n";
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "C\n";
    else
        std::cout << "Unknown type\n";
}

// Function to identify from Base reference
void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);  // use void to explicitly ignore the result
        std::cout << GREEN << "Type: A" << RESET << std::endl;
        return;
    } catch (const std::bad_cast& e) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << GREEN << "Type: B" << RESET << std::endl;
        return;
    } catch (const std::bad_cast& e) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << GREEN << "Type: C" << RESET << std::endl;
        return;
    } catch (const std::bad_cast& e) {}

    std::cout << "Unknown type\n";
}

std::ostream& operator<<(std::ostream& os, Base* base) {
    if (dynamic_cast<A*>(base) != NULL)
        os << GREEN << "A" << RESET;
    else if (dynamic_cast<B*>(base) != NULL)
        os << CYAN << "B" << RESET;
    else if (dynamic_cast<C*>(base) != NULL)
        os << YELLOW << "C" << RESET;
    else
        os << RED << "Unknown type" << RESET;
    return os;
}