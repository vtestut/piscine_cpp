#ifndef  _BRAIN_HPP
# define _BRAIN_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <map>
# include <cmath>

/******************************************************************************/
/*									DEFINES									  */
/******************************************************************************/

# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define CYAN	"\033[36m"
# define YELLOW	"\033[93m"

# define RESET	"\033[0m"
# define CLEAR	"\033[2J\033[1;1H"

# define NB_IDEAS 2

/******************************************************************************/
/*									CLASS									  */
/******************************************************************************/

class Brain {

private :
	
	std::string  *ideas;

public :

	Brain();
	Brain(const Brain & obj);
	
	~Brain();

	std::string *getIdeas();
	
	Brain & operator=(const Brain & obj);
};

#endif