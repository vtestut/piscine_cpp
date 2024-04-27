#ifndef  _BUREAUCRAT_HPP
# define _BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <stdexcept>

/******************************************************************************/
/*									DEFINES									  */
/******************************************************************************/

# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define CYAN	"\033[36m"
# define YELLOW	"\033[93m"

# define RESET	"\033[0m"
# define CLEAR	"\033[2J\033[1;1H"

/******************************************************************************/
/*									CLASS									  */
/******************************************************************************/

class Bureaucrat {

private : 

	static const std::string _defaultName;
	static const int 		 _highestGrade = 1;
	static const int 		 _lowestGrade = 150;

	const std::string		 _name;
	int						 _grade;

public :

	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat & obj);
	Bureaucrat& operator=(const Bureaucrat & obj);
	
	~Bureaucrat();
	
	std::string	getName() const;
	int			getGrade() const;

	void		incrementGrade();
	void		decrementGrade();

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

};

std::ostream& operator<<(std::ostream &out, const Bureaucrat &obj);

#endif

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

int main() {
	try {
		std::cout << GREEN "try1 : " RESET << std::endl;
		Bureaucrat Macronus("Macronus", 1);
		std::cout << Macronus;
		Macronus.incrementGrade();
	} catch (const std::exception& e) {
		std::cout << YELLOW "catch = " << e.what() << RESET << std::endl;
	}

	try {
		std::cout << GREEN "try2 : " RESET << std::endl;
		Bureaucrat poutou;
		std::cout << poutou;
		poutou.decrementGrade();
	} catch (const std::exception& e) {
		std::cout << YELLOW "catch = " << e.what() << RESET << std::endl;
	}

	try {
		std::cout << GREEN "try3 : " RESET << std::endl;
		Bureaucrat worker3("worker3", 160);
	} catch (const std::exception& e) {
		std::cout << YELLOW "catch = " << e.what() << RESET << std::endl;
	}

	try {
		std::cout << GREEN "try4 : " RESET << std::endl;
		Bureaucrat worker4("worker4", -5);
	} catch (const std::exception& e) {
		std::cout << YELLOW "catch = " << e.what() << RESET << std::endl;
	}
}
