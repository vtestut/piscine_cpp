#ifndef  _RPN_HPP
# define _RPN_HPP

# include <iostream>
# include <stack>
# include <queue>
# include <string>
# include <fstream>
# include <stdlib.h>
# include <iomanip>
# include <stdexcept>
# include <limits>
# include <algorithm>
# include <exception>

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

class RPN : std::stack<float> {

private :

	RPN ();

public :

	RPN (std::string arg);
	RPN (const RPN& o);
	~RPN();
	RPN& operator=(const RPN& o);
	
	void run ();
};

#endif
