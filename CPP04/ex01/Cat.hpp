#ifndef  _CAT_HPP
# define _CAT_HPP

# include "Animal.hpp"

class Cat : public Animal {

private :

	Brain* brain;

public :

	Cat();
	Cat(const Cat & cat);

	~Cat();

	std::string getIdea(int idx) const;
	void		setIdea(int idx, std::string idea);
	
	void		makeSound() const;

	Cat & operator=(const Cat & cat);
};

#endif