#ifndef  _WHATEVER_HPP
# define _WHATEVER_HPP

# include <iostream>
# include <string>

/******************************************************************************/
/*									DEFINES									  */
/******************************************************************************/

# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define CYAN    "\033[36m"
# define YELLOW  "\033[93m"
# define RESET   "\033[0m"

/******************************************************************************/
/*									TEMPLATES								  */
/******************************************************************************/

template <typename Type> 
void swap(Type& a, Type& b) 
{
	Type tmp = a;
	a = b;
	b = tmp;
}

template <typename Type> 
Type min(Type& a, Type& b ) 
{
	if (a < b) 
		return a;
	return b;
}

template <typename Type> 
Type max(Type& a, Type& b) 
{
	if (a > b)
		return a;
	return b;
}

#endif
