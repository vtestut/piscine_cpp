#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

/******************************************************************************/
/*							PUBLIC											  */
/******************************************************************************/

void    RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    if ( executor.getGrade() > this->getExecGrade() )
        throw AForm::GradeTooLowException();
    else {
        static int  i;
        if ( i % 2 == 0 )
            std::cout << "BZZZZZT! " << _target << " has been robotomized!" << std::endl;
        else
            std::cout << "Robotomy failed! " << _target << " is still alive." << std::endl;
        i++;
    }
}

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) 
    : AForm("Robotomy_Form", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) 
    : AForm(obj), _target(obj._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& obj) {
    ( void )obj;
    return *this;
}


