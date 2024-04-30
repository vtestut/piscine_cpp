#ifndef  _INTERN_HPP
# define _INTERN_HPP

# include "AForm.hpp"

/******************************************************************************/
/*									CLASS									  */
/******************************************************************************/

class Intern {

public :

    Intern();
    Intern(const Intern& obj);
    ~Intern();

    Intern& operator=(const Intern& obj);

    AForm*   makeForm(std::string name, std::string target);
    static AForm* createRobotomyRequestForm(std::string target);
    static AForm* createPresidentialPardonForm(std::string target);
    static AForm* createShrubberyCreationForm(std::string target);
};

#endif
