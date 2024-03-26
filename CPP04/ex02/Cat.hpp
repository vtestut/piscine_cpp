#ifndef  _CAT_HPP
# define _CAT_HPP

# include "AAnimal.hpp"

class Cat : public AAnimal {

private :

	Brain* brain;

public :

	Cat();
	Cat(const Cat & obj);

	~Cat();

	std::string	getIdea(int idx) const;
	void		setIdea(int idx, std::string idea);
	
	void		makeSound() const;

	Cat & operator=(const Cat & obj);
};

#endif