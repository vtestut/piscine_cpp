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
    : AForm("Presidential_Pardon", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj) 
    : AForm(obj), _target(obj._target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj) {
    (void)obj;
    return *this;
}
