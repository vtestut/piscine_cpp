#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {

private :

	Brain *brain;

public :

	Cat();
	Cat(const Cat & obj);

	~Cat();

	Brain *getBrain() const;

	void makeSound() const;

	Cat & operator=(const Cat & obj);
};

#endif