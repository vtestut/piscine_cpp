#ifndef  _ANIMAL_HPP
# define _ANIMAL_HPP

# include "Brain.hpp"
# include <iostream>
# include <stdexcept>
# include <string>

class Animal {

protected:

	std::string type;

public:

	Animal();
	Animal(Animal const& animal);

	virtual ~Animal();

	virtual void	makeSound() const;
	std::string		getType() const;

	Animal& operator=(Animal const& animal);
};

#endif