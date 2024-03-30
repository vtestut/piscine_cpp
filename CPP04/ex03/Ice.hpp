#ifndef  _ICE_HPP
# define _ICE_HPP

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

class Ice : public AMateria {
	
public :

	Ice(void);
	Ice(Ice const & src);
	~Ice(void);

	Ice	& operator=(Ice const & src);

	AMateria *	clone(void) const;
	void		use(ICharacter & target);
	
};

#endif