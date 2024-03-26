#ifndef  _AANIMAL_HPP
# define _AANIMAL_HPP

#include "Brain.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

class AAnimal {

protected :

	std::string type;

public :

	AAnimal();
	AAnimal(const AAnimal & aanimal);

	virtual ~AAnimal();

	virtual void makeSound() const = 0;
	std::string getType() const;

	AAnimal& operator=(const AAnimal & aanimal);
};

#endif