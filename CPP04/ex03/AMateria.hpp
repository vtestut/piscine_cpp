#ifndef  _AMATERIA_HPP
# define _AMATERIA_HPP

# include "ICharacter.hpp"
# include <string>

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

class ICharacter;

class AMateria
{

protected :
	
	std::string	_type;
	
public :

	AMateria(void);
	AMateria(AMateria const & src);
	AMateria(std::string const & type);
	virtual ~AMateria(void);
	AMateria &	operator=(AMateria const & src);

	std::string const & getType(void) const;
	
	virtual AMateria* clone(void) const = 0;		// AMateria class is abstract (clone() is a pure function)
	virtual void use(ICharacter & target);
};

#endif