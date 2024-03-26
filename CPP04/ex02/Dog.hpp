#ifndef  _DOG_HPP
# define _DOG_HPP

# include "AAnimal.hpp"

class Dog : public AAnimal {

private :

	Brain* brain;

public :

	Dog();
	Dog(const Dog & obj);

	~Dog();

	std::string	getIdea(int idx) const;
	void		setIdea(int idx, std::string idea);

	void		makeSound() const;

	Dog & operator=(const Dog & obj);
};

#endif