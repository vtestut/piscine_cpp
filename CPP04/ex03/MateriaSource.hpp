#ifndef  _MATERIASOURCE_HPP
# define _MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include <string>

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
	const std::string toDisplay() const;


	MateriaSource &	operator=(const MateriaSource & obj);
};

std::ostream& operator<<(std::ostream& os, const MateriaSource & materiaSource);

#endif