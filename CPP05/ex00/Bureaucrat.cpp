# include "Bureaucrat.hpp"

const std::string Bureaucrat::_defaultName = "philipe poutou";

Bureaucrat::Bureaucrat() : _name(_defaultName) , _grade(_lowestGrade) {
	std::cout << CYAN "constructor called" RESET << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	if (grade > this->_lowestGrade)
		throw Bureaucrat::GradeTooHighException();
	else if (grade < this->_highestGrade)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
	std::cout << CYAN "constructor called" RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) : _name(obj._name), _grade(obj._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj) {
	if (this != &obj) {
		_grade = obj._grade;
		*const_cast<std::string*>(&_name) = obj._name;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << RED "destructor called" RESET << std::endl;
}

std::string Bureaucrat::getName() const { return _name; }

int Bureaucrat::getGrade() const { return _grade; }

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

const char* Bureaucrat::GradeTooHighException::what() const throw() { return "Grade too high"; }

const char* Bureaucrat::GradeTooLowException::what() const throw() { return "Grade too low"; }

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj) {
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".\n";
	return out;
}