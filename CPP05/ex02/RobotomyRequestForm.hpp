#ifndef  _ROBOTOMYREQUESTFORM_HPP
# define _ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

/******************************************************************************/
/*									CLASS									  */
/******************************************************************************/

class RobotomyRequestForm : public AForm {

private :

    const std::string   _target;

    RobotomyRequestForm();

public :

    RobotomyRequestForm(const std::string& target );
    RobotomyRequestForm(const RobotomyRequestForm& obj);
    ~RobotomyRequestForm();

    RobotomyRequestForm &operator=(RobotomyRequestForm& obj);

    void execute(const Bureaucrat& executor) const;
};

#endif
