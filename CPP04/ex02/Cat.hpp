#ifndef  _CAT_HPP
# define _CAT_HPP

# include "AAnimal.hpp"

class Cat : public AAnimal {

private :

	Brain* brain;

public :

	Cat();
	Cat(const Cat & cat);

	~Cat();

	void makeSound() const;
	std::string getIdea(int idx) const;
	void setIdea(int idx, std::string idea);

	Cat & operator=(const Cat & cat);
};

#endif