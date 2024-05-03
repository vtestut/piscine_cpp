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

class AForm;

class Bureaucrat {

private :

	const std::string		 _name;
	int						 _grade;


public :

	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& obj);
	Bureaucrat& operator=(const Bureaucrat& obj);

	~Bureaucrat();

	static const int highestGrade = 1;
	static const int lowestGrade = 150;

	std::string getName() const;
	int         getGrade() const;

	void        signForm(AForm& form);

	void        incrementGrade();
	void        decrementGrade();

	void        executeForm(const AForm& form) const;  

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj);

#endif
