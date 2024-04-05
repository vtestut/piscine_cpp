#ifndef  _ICE_HPP
# define _ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria {
	
public :

	Ice();
	Ice(const Ice & obj);

	~Ice();

	AMateria *	clone() const;
	void		use(ICharacter & target);
	
	Ice	& operator=(const Ice & obj);
};

#endif