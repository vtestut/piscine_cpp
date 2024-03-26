#ifndef  _DOG_HPP
# define _DOG_HPP

# include "Animal.hpp"

class Dog : public Animal {

private :

	Brain* brain;

public :

	Dog();
	Dog(const Dog & dog);

	~Dog();

	std::string	getIdea(int idx) const;
	void		setIdea(int idx, std::string idea);
	
	void		makeSound() const;

	Dog & operator=(const Dog & dog);
};

#endif