#include "AForm.hpp"

AForm::AForm(const std::string& name, int signGrade, int execGrade) 
	: _formName(name), _signGrade(signGrade), _execGrade(execGrade) {
	if (signGrade < Bureaucrat::highestGrade || execGrade < Bureaucrat::highestGrade)
		throw AForm::GradeTooHighException();
	if (signGrade > Bureaucrat::lowestGrade || execGrade > Bureaucrat::lowestGrade)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& obj)
	: _formName( obj.getName() ), _signGrade( obj.getSignGrade() ), _execGrade( obj.getExecGrade() ) {}


AForm& AForm::operator=(const AForm& form) {
	if (this != &form) {
		*const_cast<std::string*>(&this->_formName) = form._formName;
		*const_cast<int*>(&this->_signGrade) = form._signGrade;
		*const_cast<int*>(&this->_execGrade) = form._execGrade;
		this->_status = form._status;
	}
	return *this;
}

// AForm& AForm::operator=( const AForm& rhs ) {
// 	if ( this != &rhs )
// 		_status = rhs.getStatus();
// 	return *this;
// }

AForm::~AForm() {}

std::string AForm::getName() const {return _formName;}
int	AForm::getSignGrade() const {return _signGrade;}
int AForm::getExecGrade() const {return _execGrade;}
bool AForm::getStatus() const {return _status;}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _signGrade)
		throw AForm::GradeTooLowException();
	else if (_status)
		std::cout << bureaucrat.getName() << " could not sign " << _formName << " because it is already signed.\n";
	else {
		std::cout << bureaucrat.getName() << " signed " << _formName << std::endl;
		_status = true;
	}
}

// void    AForm::beSigned(const Bureaucrat& bureaucrat) {
// 	if ( bureaucrat.getGrade() > _signGrade ) {
// 		throw AForm::GradeTooLowException();
// 	}
// 	_status = true;
// }

const char* AForm::GradeTooHighException::what() const throw() {return "Form grade too high";}

const char* AForm::GradeTooLowException::what() const throw() {return "Form grade too low";}

const char* AForm::NotSignedException::what() const throw() {return "Form is not signed";}

std::ostream& operator<<(std::ostream &out, const AForm& form) {
	out << "Form name: " << form.getName() << " is signable by grade " << form.getSignGrade()
		<< " and executable by grade " << form.getExecGrade() << ". It is"
		<< (form.getStatus() ? " " : " not yet ") << "signed.\n";
	return (out);
}
