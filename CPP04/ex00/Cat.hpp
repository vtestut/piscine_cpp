#ifndef  _CAT_HPP
# define _CAT_HPP

# include <iostream>
# include "Animal.hpp"

class Cat : public Animal {

public :

	Cat();
	Cat(const Cat & obj);
	
	~Cat();

	void makeSound() const;

	Cat & operator=(const Cat & obj);
};

#endif
