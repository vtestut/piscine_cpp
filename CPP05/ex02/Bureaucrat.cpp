#include "Bureaucrat.hpp"

const std::string Bureaucrat::_defaultName = "philipe poutou";

Bureaucrat::Bureaucrat() : _name(_defaultName) , _grade(lowestGrade) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) {
	if (grade > this->lowestGrade)
		throw Bureaucrat::GradeTooHighException();
	else if (grade < this->highestGrade)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) : _name(obj._name), _grade(obj._grade) {}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& rhs ) {
	if ( this != &rhs )
		_grade = rhs._grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const {return _name;}

int Bureaucrat::getGrade() const {return _grade;}

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

void Bureaucrat::signForm(AForm& form) {
	if (_grade > form.getSignGrade()) {
		std::cout << _name << " could not sign " << form.getName()
				  << " : grade is too low.\n";
	} else {
		form.beSigned(*this);
	}
	// try {
	// 	form.beSigned( *this );
	// 	std::cout << *this << " signed " << form.getName() << std::endl;
	// } catch ( AForm::GradeTooLowException& e ) {
	// 	std::cout << _name << " coulnd't sign " << form.getName() << " because " << e.what() << std::endl;
	// }
}

void Bureaucrat::executeForm(const AForm& form) const {
	try {
		form.execute( *this );
	} catch ( std::exception& e ) {
		std::cout << _name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj) {
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
	return out;
}