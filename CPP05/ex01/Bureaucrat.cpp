#include "Bureaucrat.hpp"
#include "Form.hpp"

const std::string Bureaucrat::_defaultName = "Newbie";

/******************************************************************************/
/*							PUBLIC											  */
/******************************************************************************/

void Bureaucrat::signForm(Form& form) {
	if (_grade > form.getSignGrade()) {
		std::cout << _name << " could not sign " << form.getName() << " : grade is too low.\n";
	} else {
		form.beSigned(*this);
	}
}

void Bureaucrat::incrementGrade() {
	if (_grade == Bureaucrat::highestGrade)
		throw Bureaucrat::GradeTooHighException();
	--_grade;
}

void Bureaucrat::decrementGrade() {
	if (_grade == Bureaucrat::lowestGrade)
		throw Bureaucrat::GradeTooLowException();
	++_grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() { 
	return "Grade too high"; 
}

const char* Bureaucrat::GradeTooLowException::what() const throw() { 
	return "Grade too low"; 
}

/******************************************************************************/
/*							ACCESSORS										  */
/******************************************************************************/

std::string Bureaucrat::getName() const { return _name; }

int Bureaucrat::getGrade() const { return _grade; }

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

Bureaucrat::Bureaucrat() : _name(_defaultName) , _grade(lowestGrade) {}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {
	if (grade > this->lowestGrade)
		throw Bureaucrat::GradeTooHighException();
	else if (grade < this->highestGrade)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) : _name(obj._name), _grade(obj._grade) {}

Bureaucrat::~Bureaucrat() {}

/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj) {
	if (this != &obj) {
		_grade = obj._grade;
		*const_cast<std::string*>(&_name) = obj._name;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj) {
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
	return out;
}