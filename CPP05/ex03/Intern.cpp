#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

/******************************************************************************/
/*							PUBLIC											  */
/******************************************************************************/

AForm* Intern::createRobotomyRequestForm(std::string target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(std::string target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::createShrubberyCreationForm(std::string target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeForm(std::string name, std::string target) {
    struct FormPair {
        std::string name;
        AForm* (*create)(std::string);
    };

    FormPair formPairs[] = {
        {"robotomy request", createRobotomyRequestForm},
        {"presidential pardon", createPresidentialPardonForm},
        {"shrubbery creation", createShrubberyCreationForm}
    };

    for (int i = 0; i < 3; ++i) {
        if (name == formPairs[i].name) {
            std::cout << "Intern creates " << name << std::endl;
            return formPairs[i].create(target);
        }
    }

    std::cout << "Intern cannot create " << name << " form" << std::endl;
    return NULL;
}

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

Intern::Intern() {}

Intern::Intern(const Intern& obj) {*this = obj;}

Intern::~Intern() {}

/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/

Intern& Intern::operator=(const Intern& obj) {
    (void)obj;
    return *this;
}