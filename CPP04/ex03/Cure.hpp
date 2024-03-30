#ifndef  _CURE_HPP
# define _CURE_HPP

# include "AMateria.hpp"

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

class Cure : public AMateria
{
	
public :

	Cure(void);
	Cure(Cure const & src);
	~Cure(void);
	Cure &	operator=(Cure const & src);

	AMateria *	clone(void) const;
	void		use(ICharacter & target);
	
};

#endif