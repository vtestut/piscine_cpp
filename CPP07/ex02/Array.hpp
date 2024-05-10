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

# define ARR_INT_SIZE 10  // !!!!!!!!!!!!!!!!!!!!!!

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
    explicit Array(unsigned int n);  // ! explicit ???
    Array(const Array& other);
    Array& operator=(const Array& other);
    ~Array();

    T& operator[](unsigned int i);  // ! operator[] ????
    const T& operator[](unsigned int i) const;
    unsigned int size() const;

};

template <class T>
std::ostream& operator<<(std::ostream& os, const Array<T>& arr);

# include "Array.tpp"

#endif
