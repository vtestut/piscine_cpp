#ifndef  _ANIMAL_HPP
# define _ANIMAL_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <map>
# include <cmath>
# include "Brain.hpp"

class Animal {

protected :

	std::string _type;

public : 

	Animal();
	Animal(const Animal & obj);

	virtual ~Animal();

	std::string getType() const;
	void setType(std::string);
	
	virtual void makeSound() const;
	
	Animal & operator=(const Animal & obj);
};

#endif