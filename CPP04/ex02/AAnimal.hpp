#ifndef  _AANIMAL_HPP
# define _AANIMAL_HPP

# include <iostream>
# include <stdexcept>
# include <string>

# include "Brain.hpp"

class AAnimal {

protected :

	std::string _type;

public :

	AAnimal();
	AAnimal(const AAnimal & obj);

	virtual ~AAnimal();

	std::string getType() const;

	virtual void makeSound() const = 0;

	AAnimal & operator=(const AAnimal & obj);
};

#endif