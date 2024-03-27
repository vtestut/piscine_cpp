#ifndef  _DOG_HPP
# define _DOG_HPP

# include <iostream>
# include "Animal.hpp"

class Dog : public Animal {

public :

	Dog();
	Dog(const Dog & obj);
	
	~Dog();

	void makeSound() const;

	Dog & operator=(const Dog & obj);
};

#endif