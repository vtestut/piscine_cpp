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

// ! une reference est tjr non null

template <typename T> 
void swap(T& a, T& b) 
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T> 
T min(T& a, T& b ) 
{
	return ( a < b ? a : b );
}

template <typename T> 
T max(T& a, T& b) 
{
	return ( a > b ? a : b );
}

#endif
