#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
        Bureaucrat macron("Macron", 1);
        Bureaucrat poutou("Poutou", 140);
        ShrubberyCreationForm shrubbery("Home");
        RobotomyRequestForm robotomy(CYAN "Robocop" RESET);
        PresidentialPardonForm pardon(CYAN "Thug" RESET);

        std::cout << std::endl << macron << poutou << std::endl;
        std::cout << shrubbery << robotomy << pardon << std::endl;

        std::cout << YELLOW << "\nPoutou try to sign forms" << RESET << std::endl;
        poutou.signForm(shrubbery);
        poutou.signForm(robotomy);
        poutou.signForm(pardon);

        std::cout << YELLOW << "\nPoutou try to execute forms" << RESET << std::endl;
        poutou.executeForm(shrubbery);
        poutou.executeForm(robotomy);
        poutou.executeForm(pardon);

        std::cout << YELLOW << "\nMacron try to sign forms" << RESET << std::endl;
        macron.signForm(shrubbery);
        macron.signForm(robotomy);
        macron.signForm(pardon);

        std::cout << YELLOW << "\nMacron try to execute forms" << RESET << std::endl;
        macron.executeForm(shrubbery);
        std::cout << std::endl;
        for (int i = 0; i < 4; i++) {
            macron.executeForm(robotomy);
        }
        std::cout << std::endl;
        macron.executeForm(pardon);
        std::cout << std::endl << shrubbery << robotomy << pardon << std::endl;
    return 0;
}
