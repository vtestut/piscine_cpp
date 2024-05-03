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
	Intern& operator=(const Intern& obj);

	~Intern();

	AForm* makeForm(const std::string& name, const std::string& target);
	static AForm* createRobotomyRequestForm(const std::string& target);
	static AForm* createPresidentialPardonForm(const std::string& target);
	static AForm* createShrubberyCreationForm(const std::string& target);
};

#endif
