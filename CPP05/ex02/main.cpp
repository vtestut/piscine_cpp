#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
        Bureaucrat macron("Macron", 1);
        Bureaucrat poutou("Poutou", 140);
        ShrubberyCreationForm shrub("Home");
        RobotomyRequestForm robotomy("Employee");
        PresidentialPardonForm pardon("Criminal");

        std::cout << YELLOW << "\nPoutou try to sign forms" << RESET << std::endl;
        poutou.signForm(shrub);
        poutou.signForm(robotomy);
        poutou.signForm(pardon);

        std::cout << YELLOW << "\nPoutou try to execute forms" << RESET << std::endl;
        poutou.executeForm(shrub);
        poutou.executeForm(robotomy);
        poutou.executeForm(pardon);

        std::cout << YELLOW << "\nMacron try to sign forms" << RESET << std::endl;
        macron.signForm(shrub);
        macron.signForm(robotomy);
        macron.signForm(pardon);

        std::cout << YELLOW << "\nMacron try to execute forms" << RESET << std::endl;
        macron.executeForm(shrub);
        std::cout << std::endl;
        for (int i = 0; i < 8; i++) {
            macron.executeForm(robotomy);
        }
        std::cout << std::endl;
        macron.executeForm(pardon);
        std::cout << std::endl;
    return 0;
}
