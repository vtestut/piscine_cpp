#ifndef  _PRESIDENTIALPARDONFORM_HPP
# define _PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

/******************************************************************************/
/*									CLASS									  */
/******************************************************************************/

class PresidentialPardonForm : public AForm {

private :

	std::string _target;

	PresidentialPardonForm();

public :

	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& obj);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& obj);

	~PresidentialPardonForm();
	
	void execute(const Bureaucrat& executor) const;
};

#endif
