#ifndef  _FORM_HPP
# define _FORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>
// # include "Bureaucrat.hpp"

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

class Bureaucrat;

class Form {

private : 

	Form();

	const std::string	_formName;
	const int			_signGrade;
	const int			_execGrade;
	bool 				_status;

public :

	Form(std::string name, int signGrade, int execGrade);
	Form(const Form & obj);
	Form& operator=(const Form & obj);

	~Form();

	std::string	getName() const;
	bool		getStatus() const;
	int 		getSignGrade() const;
	int			getExecGrade() const;

	void beSigned(const Bureaucrat& obj);

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream &out, const Form &obj);

#endif