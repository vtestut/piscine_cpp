#ifndef  _IMATERIASOURCE_HPP
# define _IMATERIASOURCE_HPP

# include "AMateria.hpp"
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

class IMateriaSource {

public :

	virtual ~IMateriaSource(void) {}

	virtual void		learnMateria(AMateria * m) = 0;
	virtual AMateria*	createMateria(std::string const & type) = 0;

};

#endif