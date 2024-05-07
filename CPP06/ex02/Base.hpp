#ifndef  _BASE_HPP
# define _BASE_HPP

# include <iostream>
# include <cstdlib>   // rand
# include <exception>
# include <ctime>
// # include <typeinfo>

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

class Base {

public:

	virtual ~Base() {};

};

class A : public Base {};
class B : public Base {};
class C : public Base {};

std::ostream& operator<<(std::ostream& os, Base* base);

#endif

