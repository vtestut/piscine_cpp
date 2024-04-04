#ifndef  _ANIMAL_HPP
# define _ANIMAL_HPP

# include <iostream>
# include <string>

/******************************************************************************/
/*									DEFINES									  */
/******************************************************************************/

# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define CYAN	"\033[36m"
# define YELLOW	"\033[93m"

# define RESET	"\033[0m"
# define CLEAR	"\033[2J\033[1;1H"

/******************************************************************************/
/*									CLASS									  */
/******************************************************************************/

/*	Une methode est une fonctiom membre 'virtual' dont la resolution est dynamique.
	Elle se resoud au moment de la compilation.
	Si le destructeur ~Animal n'est pas 'virtual', alors seul ~Animal() est appelé, jamais ~Cat()
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