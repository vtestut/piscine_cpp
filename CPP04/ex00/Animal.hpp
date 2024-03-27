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
	if not virtual ~Animal, than onnly ~Animal() is called, never ~Cat()
	non-final class with virtual functions should have virtual destructor
	Virtual destructor lets delete an instance of a child class through a pointer to parent class */

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