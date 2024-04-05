#ifndef  _MATERIASOURCE_HPP
# define _MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {

private :

	static int const _maxRecipes = 4;
	AMateria *		 _recipes[_maxRecipes];

	void	_initializeEmptyRecipes();
	void	_deleteRecipes();

public :

	MateriaSource();
	MateriaSource(const MateriaSource & obj);

	~MateriaSource();

	void		learnMateria(AMateria * m);
	AMateria *	createMateria(const std::string & type);
	void		displayKnownRecipes();

	MateriaSource &	operator=(const MateriaSource & obj);
};

#endif