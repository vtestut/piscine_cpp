#ifndef  _ROBOTOMYREQUESTFORM_HPP
# define _ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm {

private :

    const std::string   _target;

    RobotomyRequestForm();

public :

    RobotomyRequestForm( const std::string& target );
    RobotomyRequestForm( const RobotomyRequestForm& src );
    ~RobotomyRequestForm();

    RobotomyRequestForm &operator=( RobotomyRequestForm& rhs );

    void        execute( const Bureaucrat& executor ) const;
};

#endif
