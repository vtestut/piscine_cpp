#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int main() {

    Bureaucrat macron("Macron", 1);
    Bureaucrat poutou("Poutou", 135);
    Intern intern;

    AForm* form1;
    AForm* form2;
    AForm* form3;
    AForm* formNull;

    // Création des formulaires
    form1 = intern.makeForm("shrubbery creation", "Home");
    form2 = intern.makeForm("robotomy request", "Employee");
    form3 = intern.makeForm("presidential pardon", "Criminal");
    formNull = intern.makeForm("unknown form", "Nowhere");

    // Test des formulaires
    std::cout << YELLOW << "\nMacron tries to execute and sign forms:" << RESET << std::endl;
    if (form1) {
        macron.signForm(*form1);
        macron.executeForm(*form1);
    }
    if (form2) {
        macron.signForm(*form2);
        macron.executeForm(*form2);
    }
    if (form3) {
        macron.signForm(*form3);
        macron.executeForm(*form3);
    }
    if (formNull) {
        std::cout << RED << "An attempt was made to create and use an invalid form." << RESET << std::endl;
    }

    // Nettoyage
    delete form1;
    delete form2;
    delete form3;

    return 0;
}
