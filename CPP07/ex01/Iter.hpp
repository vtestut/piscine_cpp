#ifndef  _ITER_HPP
# define _ITER_HPP

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

# define LEN 5

/******************************************************************************/
/*									TEMPLATES								  */
/******************************************************************************/


template <typename Type, typename Func>
void iter(Type* array, size_t lenght, Func function) 
{
	if (!array) 
	{
		std::cout << "Array is NULL" << std::endl;
		return;
	}
	for (size_t i = 0; i < lenght; ++i)
		function(array[i]);
}

template<typename Type>
void print(const Type& obj)
{
	std::cout << obj << std::endl;
}


#endif