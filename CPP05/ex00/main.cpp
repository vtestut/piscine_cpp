#include "Bureaucrat.hpp"

int main() {
	try {
		std::cout << GREEN "try1 : " RESET << std::endl;
		Bureaucrat president("President", 1);
		std::cout << president;
		std::cout << "try to upgrade President" << std::endl;
		president.incrementGrade(); // exception thrown 
		president.decrementGrade(); // should not be executed
		std::cout << president;		// should not be executed
	} catch (const std::exception& e) {
		std::cout << YELLOW "catch = " << e.what() << RESET << std::endl;
	}

	try {
		std::cout << GREEN "try2 : " RESET << std::endl;
		Bureaucrat newbie;
		std::cout << newbie;
		std::cout << "try to decreased Newbie" << std::endl;
		newbie.decrementGrade();
	} catch (const std::exception& e) {
		std::cout << YELLOW "catch = " << e.what() << RESET << std::endl;
	}

	try {
		std::cout << GREEN "try3 : " RESET << std::endl;
		std::cout << "try to create a Bureaucrat rank 160" << std::endl;
		Bureaucrat random("random", 160);
	} catch (const std::exception& e) {
		std::cout << YELLOW "catch = " << e.what() << RESET << std::endl;
	}

	try {
		std::cout << GREEN "try4 : " RESET << std::endl;
		std::cout << "try to create a Bureaucrat rank -5" << std::endl;
		Bureaucrat random2("ranndom2", -5);
	} catch (const std::exception& e) {
		std::cout << YELLOW "catch = " << e.what() << RESET << std::endl;
	}
}
