#include "Form.hpp"
#include "Bureaucrat.hpp"

/******************************************************************************/
/*							PUBLIC											  */
/******************************************************************************/

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _signGrade)
		throw Form::GradeTooLowException();
	else if (_status)
		std::cout << bureaucrat.getName() << " could not sign " << _formName << " because it is already signed.\n";
	else {
		std::cout << bureaucrat.getName() << " signed " << _formName << std::endl;
		_status = true;
	}
}

const char* Form::GradeTooHighException::what() const throw() { 
	return "Form grade too high"; 
}

const char* Form::GradeTooLowException::what() const throw() { 
	return "Form grade too low"; 
}

/******************************************************************************/
/*							ACCESSORS										  */
/******************************************************************************/

std::string Form::getName() 		const { return _formName; }
int 		Form::getSignGrade() 	const { return _signGrade; }
int 		Form::getExecGrade() 	const { return _execGrade; }
bool 		Form::getStatus() 		const { return _status; }

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

Form::Form() : _formName("Basic Form"), _signGrade(Bureaucrat::lowestGrade),
			_execGrade(Bureaucrat::lowestGrade), _status(false) {}

Form::Form(const std::string name, int signGrade, int executeGrade)
	: _formName(name), _signGrade(signGrade), _execGrade(executeGrade), _status(false) {
	if (signGrade < Bureaucrat::highestGrade || executeGrade < Bureaucrat::highestGrade)
		throw Form::GradeTooHighException();
	if (signGrade > Bureaucrat::lowestGrade || executeGrade > Bureaucrat::lowestGrade)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& obj) : _formName(obj._formName), _signGrade(obj._signGrade), 
		_execGrade(obj._execGrade), _status(obj._status) {}

Form::~Form() {}

/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/

Form& Form::operator=(const Form& obj) {
    if ( this != &obj)
        _status = obj.getStatus();
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Form& obj) {
	out << "Form " << obj.getName() << " is signable by grade " << obj.getSignGrade()
	   << " and executable by grade " << obj.getExecGrade() << ". It is"
	   << (obj.getStatus() ? " " : RED " not yet " RESET) << RED "signed.\n" RESET;
	return out;
}
