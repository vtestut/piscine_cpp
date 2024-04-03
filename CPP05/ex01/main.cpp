#include "Bureaucrat.hpp"
#include "Form.hpp"
// #include <cstdlib>


int main() {
	Bureaucrat marconus("Marconus", 1);
	Bureaucrat attal("Attal", 2);
	Bureaucrat poutou("Poutou", 150);
	
	Form nuclearStrike("NuclearStrike", 40, 1);
	Form takeTheGarbageOut("TakeTheGarbageOut", 140, 140);

	try {
		Form impossible("Impossible", 0, 30);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	marconus.signForm(nuclearStrike);
	attal.signForm(nuclearStrike);
	poutou.signForm(nuclearStrike);
	poutou.signForm(takeTheGarbageOut);

	std::cout << std::endl;

	nuclearStrike.beSigned(marconus);
	takeTheGarbageOut.beSigned(marconus);
	try {
		nuclearStrike.beSigned(attal);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	takeTheGarbageOut.beSigned(attal);
	try {
		nuclearStrike.beSigned(poutou);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		takeTheGarbageOut.beSigned(poutou);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
