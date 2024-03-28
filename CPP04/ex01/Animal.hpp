#ifndef  _ANIMAL_HPP
# define _ANIMAL_HPP

# include <iostream>
# include <string>
# include <stdexcept>

# include "Brain.hpp"

/*	Une methode est une fonctiom membre 'virtual' dont la resolution est dynamique.
	Elle se resoud au moment de la compilation.
	Si la le destructeur ~Animal n'est pas 'virtual', alors seul ~Animal() est appelé, jamais ~Cat()
	Les classes meres avec des fonctions virtuelles devraient avoir un destructeur virtuel
	Un destructeur virtuel permet de supprimer une instance d'une classe fille via un pointeur vers la classe parent */

class Animal {

protected :

	std::string _type;

public :

	Animal();
	Animal(const Animal & obj);

	virtual ~Animal();

	std::string		getType() const;

	virtual void	makeSound() const;

	Animal & operator=(const Animal & obj);
};

#endif