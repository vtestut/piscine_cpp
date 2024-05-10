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

/******************************************************************************/
/*									TEMPLATES								  */
/******************************************************************************/

template <typename T, typename F>
void iter(T* array, size_t lenght, F func) 
{
	if (array == NULL) {
		std::cerr << "Error: Array pointer is NULL." << std::endl;
		return;
	}
	for (size_t i = 0; i < lenght; ++i)
		func(array[i]);
}

template<typename T>
void print(const T& elem)
{
	std::cout << elem << std::endl;
}

#endif