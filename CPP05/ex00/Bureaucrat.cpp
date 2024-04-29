# include "Bureaucrat.hpp"

const std::string Bureaucrat::_defaultName = "Newbie";

/******************************************************************************/
/*							PUBLIC											  */
/******************************************************************************/

void Bureaucrat::incrementGrade() {
	if (_grade == Bureaucrat::_highestGrade)
		throw Bureaucrat::GradeTooHighException();
	--_grade;
}

void Bureaucrat::decrementGrade() {
	if (_grade == Bureaucrat::_lowestGrade)
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

std::string Bureaucrat::getName() const { 
	return _name; 
}

int Bureaucrat::getGrade() const { 
	return _grade; 
}

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

Bureaucrat::Bureaucrat() : _name(_defaultName) , _grade(_lowestGrade) {
	std::cout << CYAN "constructor called" RESET << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	if (grade > this->_lowestGrade)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < this->_highestGrade)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = grade;
	std::cout << CYAN "constructor called" RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) : _name(obj._name), _grade(obj._grade) {}

Bureaucrat::~Bureaucrat() {
	std::cout << RED "destructor called" RESET << std::endl;
}

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