#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

void subjectTest() {
	std::cout << "\nSubject Test :" << std::endl;
	
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", CYAN "Bender" RESET);

	Bureaucrat macron("Macron", 1);
	macron.signForm(*rrf);
	macron.executeForm(*rrf);
	std::cout << std::endl;
	delete rrf;
}

int main() {
	subjectTest();

	Bureaucrat macron("Macron", 1);
	Intern intern;

	AForm* forms[4];
	std::string formNames[4] = {"shrubbery creation", 
								"robotomy request", 
								"presidential pardon", 
								"Unknown"};
	std::string targets[4] = {"Home", CYAN "Robocop" RESET, CYAN "Thug" RESET , "Unknown"};

	for (int i = 0; i < 4; i++) {
		try {
			forms[i] = intern.makeForm(formNames[i], targets[i]);
			if (forms[i] == NULL) {
				throw std::runtime_error("Form creation failed: " + formNames[i]);
			}
			macron.signForm(*forms[i]);
			macron.executeForm(*forms[i]);
			std::cout << std::endl;
		} catch (const std::exception& e) {
			std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
		}
	}
	for (int i = 0; i < 4; i++) {
		delete forms[i];
	}
	return 0;
}
