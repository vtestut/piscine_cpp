#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

/******************************************************************************/
/*							PUBLIC											  */
/******************************************************************************/

void    RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	if ( executor.getGrade() > this->getExecGrade() )
		throw AForm::GradeTooLowException();
	else if (executor.getGrade() > this->getExecGrade()) {
		throw AForm::GradeTooLowException();
	} else {
		static int  i;
		if ( i % 2 == 0 )
			std::cout << "* Clic Clang Bzzt! * " << _target << " has been robotomized successfully" << std::endl;
		else
			std::cout << "Robotomy failed! " << _target << " is still human" << std::endl;
		i++;
	}
}

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) 
	: AForm(GREEN "robotomy request" RESET, 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) 
	: AForm(obj), _target(obj._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj) {
	this->_target = obj._target;
	return *this;
}
