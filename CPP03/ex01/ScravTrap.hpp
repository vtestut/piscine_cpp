#ifndef  _SCRAVTRAP_HPP
# define _SCRAVTRAP_HPP

# include <iostream>
# include <string>
//# include <>

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

class ScravTrap {

private:
	
	int	_n;
	int	_getValue(void) const;

public:

	ScravTrap(void);
	ScravTrap(int const p1);
	ScravTrap(ScravTrap const & src);
	~ScravTrap(void);
	

	void	setValue(int const p1);

	ScravTrap &	operator=(ScravTrap const & rhs);
	ScravTrap		operator+(ScravTrap const & rhs) const;	

};

/******************************************************************************/
/*									PROTOYPES								  */
/******************************************************************************/

// std::ostream &	operator<<(std::ostream & out, ScravTrap const & i);

#endif
