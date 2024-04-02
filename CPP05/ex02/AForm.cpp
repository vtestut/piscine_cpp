#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string name, int signGrade, int executeGrade)
	: _formName(name), _signGrade(signGrade), _execGrade(executeGrade), _status(false) {
	if (signGrade < Bureaucrat::highestGrade || executeGrade < Bureaucrat::highestGrade)
		throw AForm::GradeTooHighException();
	if (signGrade > Bureaucrat::lowestGrade || executeGrade > Bureaucrat::lowestGrade)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& form)
	: _formName(form._formName), _signGrade(form._signGrade), _execGrade(form._execGrade),
	  _status(form._status) {}

AForm& AForm::operator=(const AForm& form) {
	if (this != &form) {
		*const_cast<std::string*>(&this->_formName) = form._formName;
		*const_cast<int*>(&this->_signGrade) = form._signGrade;
		*const_cast<int*>(&this->_execGrade) = form._execGrade;
		this->_status = form._status;
	}
	return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const { return _formName; }
int AForm::getSignGrade() const { return _signGrade; }
int AForm::getExecGrade() const { return _execGrade; }
bool AForm::getStatus() const { return _status; }

void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _signGrade)
		throw AForm::GradeTooLowException();
	else if (_status)
		std::cout << bureaucrat.getName() << " could not sign " << _formName
				  << " because it is already signed.\n";
	else {
		std::cout << bureaucrat.getName() << " signed " << _formName << std::endl;
		_status = true;
	}
}

const char* AForm::GradeTooHighException::what() const throw() { return "AForm grade too high"; }

const char* AForm::GradeTooLowException::what() const throw() { return "AForm grade too low"; }

std::ostream& operator<<(std::ostream& os, const AForm& form) {
	os << "AForm " << form.getName() << " is signable by grade " << form.getSignGrade()
	   << " and executable by grade " << form.getExecGrade() << ". It is"
	   << (form.getStatus() ? " " : " not yet ") << "signed.\n";
	return os;
}