#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

/******************************************************************************/
/*							PUBLIC											  */
/******************************************************************************/

void    PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	else if (executor.getGrade() > this->getExecGrade()) {
		throw AForm::GradeTooLowException();
	} else {
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
}

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) 
	: AForm(GREEN "presidential pardon" RESET, 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj) 
	: AForm(obj), _target(obj._target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj) {
	this->_target = obj._target;
	return *this;
}
