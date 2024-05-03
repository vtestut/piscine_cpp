#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << YELLOW "Bureaucrats operator <<" RESET << std::endl;
    Bureaucrat macron("Macron", 1);
    Bureaucrat attal("Attal", 2);
    Bureaucrat poutou("Poutou", 150);
    std::cout << macron << attal << poutou;

    std::cout << YELLOW "\nForms operator <<" RESET << std::endl;
    Form nuclearStrike(CYAN "Nuclear Strike Authorization" RESET, 5, 2);
    Form bulbReplacement(CYAN "Bulb Replacement Authorization" RESET, 149, 150);
    std::cout << nuclearStrike << bulbReplacement;

    std::cout << std::endl << YELLOW "tests for signing" RESET << std::endl;
    std::cout << GREEN "Macron tries to sign 'Nuclear Strike Authorization':" RESET << std::endl;
    macron.signForm(nuclearStrike);
    std::cout << GREEN "Attal tries to sign 'Nuclear Strike Authorization':" RESET << std::endl;
    attal.signForm(nuclearStrike);
    std::cout << GREEN "Poutou tries to sign 'Bulb replacement form':" RESET << std::endl;
    poutou.signForm(bulbReplacement);
	attal.signForm(bulbReplacement);
    std::cout << std::endl << nuclearStrike << bulbReplacement;

	std::cout << std::endl;
    try {
        std::cout << YELLOW "Try to create a form with a grade too high" RESET << std::endl;
        Form tooHighForm("tooHighForm", 0, 30);
    } catch (std::exception& e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    try {
        std::cout << YELLOW "Try to create a form with a grade too low" RESET << std::endl;
        Form tooLowForm("tooLowForm", 100, 151);
    } catch (std::exception& e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    try {
        std::cout << YELLOW "Try to create a bureaucrat with a grade too high" RESET << std::endl;
        Bureaucrat tooHigh("tooHigh", 0);
    } catch (std::exception& e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    try {
        std::cout << YELLOW "Try to create a bureaucrat with a grade too low" RESET << std::endl;
        Bureaucrat tooLow("tooLow", 151);
    } catch (std::exception& e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    return (0);
}
