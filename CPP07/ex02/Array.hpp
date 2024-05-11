#ifndef  ARRAY_HPP
# define ARRAY_HPP

# include <cstdlib>
# include <ctime>
# include <stdexcept>
# include <iostream>

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

template <typename T>
class Array {

private :

	T* _elems;
	unsigned int _size;

public :

	Array();
	Array(const Array& other);
	explicit Array(unsigned int n);  // ! explicit ???
	Array& operator=(const Array& other);
	~Array();
	
	unsigned int size() const;

	T& operator[](unsigned int i);  // ! operator[] ????
	const T& operator[](unsigned int i) const;

};

template <class T>
std::ostream& operator<<(std::ostream& os, const Array<T>& arr);

# include "Array.tpp"

#endif
