#ifndef  _ROBOTOMYREQUESTFORM_HPP
# define _ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

/******************************************************************************/
/*									CLASS									  */
/******************************************************************************/

class RobotomyRequestForm : public AForm {

private :

	std::string   _target;

	RobotomyRequestForm();

public :

	RobotomyRequestForm(const std::string& target );
	RobotomyRequestForm(const RobotomyRequestForm& obj);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& obj);

	~RobotomyRequestForm();

	void execute(const Bureaucrat& executor) const;
};

#endif
