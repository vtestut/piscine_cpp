#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {

private :
	
	Brain *brain;

public :

	Dog();
	Dog(const Dog & obj);
	
	~Dog();

	Brain *getBrain  () const;
	
	void makeSound  () const;
	
	Dog & operator=(const Dog & obj);
};

#endif
