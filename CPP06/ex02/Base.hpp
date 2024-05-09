#ifndef  _BASE_HPP
# define _BASE_HPP

# include <iostream>
# include <cstdlib>
# include <exception>
# include <ctime>

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

Base *generate();
void identify(Base* p);
void identify(Base& p);

#endif

