#ifndef  _CURE_HPP
# define _CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria {
	
public :

	Cure();
	Cure(const Cure & obj);

	~Cure();

	AMateria *	clone() const;
	void		use(ICharacter & target);
	
	Cure & operator=(const Cure & obj);
};

#endif