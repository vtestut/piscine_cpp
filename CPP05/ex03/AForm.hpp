#ifndef  _AFORM_HPP
# define _AFORM_HPP

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

class Bureaucrat;

class AForm {

private :

	const std::string	_formName;
	const int			_signGrade;
	const int			_execGrade;
	bool 				_status;

public :

	AForm();
	AForm(const std::string name, int signGrade, int execGrade);
	AForm(const AForm& obj);
	AForm& operator=(const AForm& obj);

	virtual ~AForm();

	std::string getName() const;
	bool		getStatus() const;
	int			getSignGrade() const;
	int			getExecGrade() const;

	void		beSigned(const Bureaucrat& bureaucrat);

	virtual void execute(const Bureaucrat& executor) const = 0;

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class NotSignedException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& out, const AForm& obj);

#endif
