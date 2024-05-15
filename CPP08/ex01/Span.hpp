#ifndef  _SPAN_HPP
# define _SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <stdexcept>
# include <iterator>

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

class Span {

private :

	Span();
	std::vector<int> _container;
	unsigned int 	 _sizeMax;

public :

	Span(unsigned int n);
	Span(const Span& obj);
	Span& operator=(const Span& obj);
	~Span() {};

	void addNumber(int number);
	void addNumbers(std::vector<int>::iterator start, std::vector<int>::iterator end);
	int	 shortestSpan() const;
	int  longestSpan() const;

};

#endif
