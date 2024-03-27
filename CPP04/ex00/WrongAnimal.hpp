#ifndef  _WRONGANIMAL_HPP
# define _WRONGANIMAL_HPP

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

class WrongAnimal {

protected :
	
	std::string _type;

public :

	WrongAnimal();
	WrongAnimal(const WrongAnimal & obj);
	
	~WrongAnimal();

	void makeSound() const;
	std::string getType() const;

	WrongAnimal & operator=(const WrongAnimal & obj);
};

#endif