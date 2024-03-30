#ifndef  _MATERIASOURCE_HPP
# define _MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

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

class MateriaSource : public IMateriaSource {

private :

	static int const	_maxRecipes = 4;
	AMateria *	_recipes[_maxRecipes];

	void	_initializeEmptyRecipes(void);
	void	_deleteRecipes(void);

public :

	MateriaSource(void);
	MateriaSource(MateriaSource const & src);
	~MateriaSource(void);

	MateriaSource &	operator=(MateriaSource const & src);

	void		learnMateria(AMateria * m);
	AMateria *	createMateria(std::string const & type);
	void		displayKnownRecipes(void);

};

#endif