#ifndef  _BRAIN_HPP
# define _BRAIN_HPP

# include <iostream>

/******************************************************************************/
/*									DEFINES									  */
/******************************************************************************/

# define NUM_IDEAS 100

# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define CYAN	"\033[36m"
# define YELLOW	"\033[93m"

# define RESET	"\033[0m"
# define CLEAR	"\033[2J\033[1;1H"

/******************************************************************************/
/*									CLASS									  */
/******************************************************************************/

class Brain {

public :

	Brain();
	Brain(const Brain & brain);
	
	~Brain();
	
	std::string ideas[NUM_IDEAS];

	Brain& operator=(const Brain & brain);
};

#endif