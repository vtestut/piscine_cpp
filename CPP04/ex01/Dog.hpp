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

	void makeSound() const;
	std::string getIdea(int idx) const;
	void setIdea(int idx, std::string idea);

	Dog & operator=(const Dog & dog);
};

#endif