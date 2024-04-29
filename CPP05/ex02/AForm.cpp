#include "AForm.hpp"

/******************************************************************************/
/*							PUBLIC											  */
/******************************************************************************/

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

/******************************************************************************/
/*							ACCESSORS										  */
/******************************************************************************/

std::string AForm::getName() const {return _formName;}
int	AForm::getSignGrade() const {return _signGrade;}
int AForm::getExecGrade() const {return _execGrade;}
bool AForm::getStatus() const {return _status;}

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

AForm::AForm() : _formName("Basic Form"), _signGrade(Bureaucrat::lowestGrade),
			_execGrade(Bureaucrat::lowestGrade), _status(false) {}

AForm::AForm(const std::string& name, int signGrade, int execGrade) 
	: _formName(name), _signGrade(signGrade), _execGrade(execGrade) {
	if (signGrade < Bureaucrat::highestGrade || execGrade < Bureaucrat::highestGrade)
		throw AForm::GradeTooHighException();
	if (signGrade > Bureaucrat::lowestGrade || execGrade > Bureaucrat::lowestGrade)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& obj) : _formName(obj._formName), _signGrade(obj._signGrade), 
		_execGrade(obj._execGrade), _status(obj._status) {}

AForm::~AForm() {}

/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/

// AForm& AForm::operator=( const AForm& rhs ) {
// 	if ( this != &rhs )
// 		_status = rhs.getStatus();
// 	return *this;
// }

AForm& AForm::operator=(const AForm& form) {
	if (this != &form) {
		*const_cast<std::string*>(&this->_formName) = form._formName;
		*const_cast<int*>(&this->_signGrade) = form._signGrade;
		*const_cast<int*>(&this->_execGrade) = form._execGrade;
		this->_status = form._status;
	}
	return *this;
}

std::ostream& operator<<(std::ostream &out, const AForm& obj) {
	out << "Form name: " << obj.getName() << " is signable by grade " << obj.getSignGrade()
		<< " and executable by grade " << obj.getExecGrade() << ". It is"
		<< (obj.getStatus() ? " " : " not yet ") << "signed.\n" RESET;
	return (out);
}
