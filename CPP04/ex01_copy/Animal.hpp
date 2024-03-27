#ifndef  _ANIMAL_HPP
# define _ANIMAL_HPP

# include <iostream>
# include <string>
# include <stdexcept>

# include "Brain.hpp"

class Animal {

protected :

	std::string _type;

public :

	Animal();
	Animal(const Animal & obj);

	virtual ~Animal();

	std::string		getType() const;

	virtual void	makeSound() const;

	Animal & operator=(const Animal & obj);
};

#endif