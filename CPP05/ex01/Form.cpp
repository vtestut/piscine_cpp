#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string name, int signGrade, int executeGrade)
	: _formName(name), _signGrade(signGrade), _execGrade(executeGrade), _status(false) {
	if (signGrade < Bureaucrat::highestGrade || executeGrade < Bureaucrat::highestGrade)
		throw Form::GradeTooHighException();
	if (signGrade > Bureaucrat::lowestGrade || executeGrade > Bureaucrat::lowestGrade)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& form)
	: _formName(form._formName), _signGrade(form._signGrade), _execGrade(form._execGrade),
	  _status(form._status) {}

Form& Form::operator=(const Form& form) {
	if (this != &form) {
		*const_cast<std::string*>(&this->_formName) = form._formName;
		*const_cast<int*>(&this->_signGrade) = form._signGrade;
		*const_cast<int*>(&this->_execGrade) = form._execGrade;
		this->_status = form._status;
	}
	return *this;
}

Form::~Form() {}

std::string Form::getName() const { return _formName; }
int Form::getSignGrade() const { return _signGrade; }
int Form::getExecGrade() const { return _execGrade; }
bool Form::getStatus() const { return _status; }

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _signGrade)
		throw Form::GradeTooLowException();
	else if (_status)
		std::cout << bureaucrat.getName() << " could not sign " << _formName
				  << " because it is already signed.\n";
	else {
		std::cout << bureaucrat.getName() << " signed " << _formName << std::endl;
		_status = true;
	}
}

const char* Form::GradeTooHighException::what() const throw() { return "Form grade too high"; }

const char* Form::GradeTooLowException::what() const throw() { return "Form grade too low"; }

std::ostream& operator<<(std::ostream& out, const Form& form) {
	out << "Form " << form.getName() << " is signable by grade " << form.getSignGrade()
	   << " and executable by grade " << form.getExecGrade() << ". It is"
	   << (form.getStatus() ? " " : " not yet ") << "signed.\n";
	return (out);
}
