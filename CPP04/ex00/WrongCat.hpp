#ifndef  _WRONGCAT_HPP
# define _WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

public :

	WrongCat();
	WrongCat(const WrongCat & obj);

	~WrongCat();

	void makeSound() const;

	WrongCat & operator=(const WrongCat & obj);

};

#endif
