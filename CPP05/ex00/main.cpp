#include "Bureaucrat.hpp"

int main() {
	try {
		std::cout << GREEN "try1 : " RESET << std::endl;
		Bureaucrat Macronus("Macronus", 1);
		std::cout << Macronus;
		Macronus.incrementGrade();
	} catch (const std::exception& e) {
		std::cout << YELLOW "catch = " << e.what() << RESET << std::endl;
	}

	try {
		std::cout << GREEN "try2 : " RESET << std::endl;
		Bureaucrat poutou;
		std::cout << poutou;
		poutou.decrementGrade();
	} catch (const std::exception& e) {
		std::cout << YELLOW "catch = " << e.what() << RESET << std::endl;
	}

	try {
		std::cout << GREEN "try3 : " RESET << std::endl;
		Bureaucrat worker3("worker3", 160);
	} catch (const std::exception& e) {
		std::cout << YELLOW "catch = " << e.what() << RESET << std::endl;
	}

	try {
		std::cout << GREEN "try4 : " RESET << std::endl;
		Bureaucrat worker4("worker4", -5);
	} catch (const std::exception& e) {
		std::cout << YELLOW "catch = " << e.what() << RESET << std::endl;
	}
}
