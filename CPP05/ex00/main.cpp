#include "Bureaucrat.hpp"

int main() {
	try {
		std::cout << GREEN "try1 : " RESET << std::endl;
		Bureaucrat b1("Macronus", 1);
		std::cout << b1;
		b1.incrementGrade();
	} catch (const std::exception& e) {
		std::cout << YELLOW "catch = " << e.what() << RESET << std::endl;
	}

	try {
		std::cout << GREEN "try2 : " RESET << std::endl;
		Bureaucrat b2;
		std::cout << b2;
		b2.decrementGrade();
	} catch (const std::exception& e) {
		std::cout << YELLOW "catch = " << e.what() << RESET << std::endl;
	}

	try {
		std::cout << GREEN "try3 : " RESET << std::endl;
		Bureaucrat b3("b3", 160);
	} catch (const std::exception& e) {
		std::cout << YELLOW "catch = " << e.what() << RESET << std::endl;
	}

	try {
		std::cout << GREEN "try4 : " RESET << std::endl;
		Bureaucrat b4("b4", -5);
	} catch (const std::exception& e) {
		std::cout << YELLOW "catch = " << e.what() << RESET << std::endl;
	}
}
