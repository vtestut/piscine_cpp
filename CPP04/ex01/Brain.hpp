#ifndef  _BRAIN_HPP
# define _BRAIN_HPP

# include <iostream>
//# include <>

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

class Brain {

private:
	

public:

	Brain();
	Brain(const Brain & obj);
	~Brain();


	Brain & operator=(const Brain & obj);

};

/******************************************************************************/
/*									PROTOYPES								  */
/******************************************************************************/

// std::ostream &	operator<<(std::ostream & out, const Brain & obj);

#endif
